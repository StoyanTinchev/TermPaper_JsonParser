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
    for (auto &[jsonKey, element] : data) {
        if (jsonKey->get_key() == key) {
            results.push_back(element->to_string());
        }
        std::vector<std::string> sub_results = element->search(key);
        results.insert(results.end(), sub_results.begin(), sub_results.end());
    }
    return results;
}

bool JsonObject::contains(const std::string &value) {
    for (auto &[jsonKey, element] : data) {
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

    for (auto &[jsonKey, element] : data) {
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
