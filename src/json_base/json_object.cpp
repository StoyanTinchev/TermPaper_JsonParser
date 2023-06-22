#include <json_base/json_object.h>
#include <json_exceptions.h>
#include <json_base/json_value.h>

JsonObject::JsonObject() = default;

JsonObject::~JsonObject() {
    for (auto &pair: data) {
        delete pair.first;
        delete pair.second;
    }
}

void JsonObject::add_element(JsonKey *key, JsonElement *value) {
    data.emplace_back(key, value);
}

JsonElement *JsonObject::get_element(const std::string &key) {
    for (auto &pair: data) {
        if (pair.first->get_key() == key) {
            return pair.second;
        }
    }
    throw JsonException("Key not found in JSON object.");
}

std::string JsonObject::to_string() const {
    std::string result = "{";
    for (const auto &pair: data) {
        result += pair.first->to_string() + ": " + pair.second->to_string() + ", ";
    }
    if (!data.empty()) {
        result.pop_back();
        result.pop_back();
    }
    result += "}";
    return result;
}

std::vector<std::string> JsonObject::search(const std::string &key) {
    std::vector<std::string> results;
    for (auto &[jsonKey, element]: data) {
        if (jsonKey->get_key() == key) {
            results.push_back(element->to_string());
        }
        std::vector<std::string> sub_results = element->search(key);
        results.insert(results.end(), sub_results.begin(), sub_results.end());
    }
    return results;
}

bool JsonObject::contains(const std::string &value) {
    for (auto &[jsonKey, element]: data) {
        if (element->contains(value)) {
            return true;
        }
    }
    return false;
}

void JsonObject::set(const std::vector<std::string> &path, const std::string &new_value) {
    if (path.empty()) {
        throw InvalidPathError("Path must not be empty when setting a value");
    }

    for (auto &[jsonKey, element]: data) {
        if (jsonKey->get_key() == path[0]) {
            if (path.size() == 1) {
                delete element;
                element = new JsonValue(new_value);
            } else {
                std::vector<std::string> sub_path(path.begin() + 1, path.end());
                element->set(sub_path, new_value);
            }
            return;
        }
    }

    throw ElementNotFoundError("Key not found in object: " + path[0]);
}

void JsonObject::create(const std::vector<std::string> &path, const std::string &value) {
    std::string key = path[0];

    auto it = find_element(key);

    if (path.size() > 1) {
        if (it == data.end()) {
            throw ElementNotFoundError("Element not found at specified path");
        }
        std::vector<std::string> newPath(path.begin() + 1, path.end());
        it->second->create(newPath, value);
    } else {
        if (it != data.end()) {
            throw ElementAlreadyExistsError("Element already exists at specified path");
        }
        data.push_back({new JsonKey(key), new JsonValue(value)});
    }
}

void JsonObject::delete_element(const std::vector<std::string> &path) {
    if (path.empty()) {
        throw InvalidPathError("Path cannot be empty for JsonObject");
    }

    auto it = find_element(path[0]);

    if (it == data.end()) {
        throw ElementNotFoundError("Key not found in JsonObject");
    }

    if (path.size() == 1) {
        delete it->first;
        delete it->second;
        data.erase(it);
    } else {
        std::vector<std::string> subPath(path.begin() + 1, path.end());
        it->second->delete_element(subPath);
    }
}

void JsonObject::move(const std::vector<std::string> &fromPath, const std::vector<std::string> &toPath) {
    if (fromPath.empty()) {
        throw InvalidPathError("Invalid path");
    }

    auto it = find_element(fromPath[0]);

    if (it == data.end()) {
        throw InvalidPathError("Element not found");
    }

    if (fromPath.size() == 1) {
        std::pair<JsonKey *, JsonElement *> movedElement = *it;
        data.erase(it);
        if (toPath.empty()) {
            throw InvalidPathError("Cannot add element to object without a key");
        }
        add_element(new JsonKey(toPath[0]), movedElement.second);
    } else {
        it->second->move(std::vector<std::string>(fromPath.begin() + 1, fromPath.end()), toPath);
    }
}

std::vector<std::pair<JsonKey *, JsonElement *>>::iterator JsonObject::find_element(const std::string &key) {
    for (auto it = data.begin(); it != data.end(); ++it) {
        if (it->first->get_key() == key) {
            return it;
        }
    }
    return data.end();
}
