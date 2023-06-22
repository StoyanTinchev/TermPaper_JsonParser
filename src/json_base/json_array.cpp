#include <json_base/json_array.h>
#include <json_exceptions.h>
#include <json_base/json_value.h>

JsonArray::JsonArray() = default;

JsonArray::~JsonArray() {
    for (auto &element: data) {
        delete element;
    }
}

void JsonArray::add_element(JsonElement *value) {
    data.push_back(value);
}

JsonElement *JsonArray::get_element(int index) {
    if (index < 0 || index >= data.size()) {
        throw JsonException("Array index out of bounds.");
    }
    return data[index];
}

std::string JsonArray::to_string() const {
    std::string result = "[";
    for (const auto &element: data) {
        result += element->to_string() + ", ";
    }
    if (!data.empty()) {
        result.pop_back();
        result.pop_back();
    }
    result += "]";
    return result;
}

std::vector<std::string> JsonArray::search(const std::string &key) {
    std::vector<std::string> results;
    for (JsonElement *element: data) {
        std::vector<std::string> sub_results = element->search(key);
        results.insert(results.end(), sub_results.begin(), sub_results.end());
    }
    return results;
}

bool JsonArray::contains(const std::string &value) {
    for (JsonElement *element: data) {
        if (element->contains(value)) {
            return true;
        }
    }
    return false;
}


void JsonArray::set(const std::vector<std::string> &path, const std::string &new_value) {
    if (path.empty()) {
        throw InvalidPathError("Path must not be empty when setting a value");
    }

    int index;
    try {
        index = std::stoi(path[0]);
    } catch (const std::invalid_argument &e) {
        throw InvalidPathError("Array index must be an integer: " + path[0]);
    }

    if (index < 0 || index >= data.size()) {
        throw ElementNotFoundError("Array index out of range: " + path[0]);
    }

    if (path.size() == 1) {
        delete data[index];
        data[index] = new JsonValue(new_value);
    } else {
        std::vector<std::string> sub_path(path.begin() + 1, path.end());
        data[index]->set(sub_path, new_value);
    }
}

void JsonArray::create(const std::vector<std::string> &path, const std::string &value) {
    int index = std::stoi(path[0]);

    if (index < 0 || index >= data.size()) {
        throw ElementNotFoundError("Index out of bounds");
    }

    if (path.size() > 1) {
        std::vector<std::string> newPath(path.begin() + 1, path.end());
        data[index]->create(newPath, value);
    } else {
        if (data[index]) {
            throw ElementAlreadyExistsError("Element already exists at specified path");
        }
        data[index] = new JsonValue(value);
    }
}

void JsonArray::delete_element(const std::vector<std::string> &path) {
    if (path.empty()) {
        throw InvalidPathError("Path cannot be empty for JsonArray");
    }

    int index = std::stoi(path[0]);

    if (index < 0 || index >= data.size()) {
        throw ElementNotFoundError("Index out of range in JsonArray");
    }

    if (path.size() == 1) {
        delete data[index];
        data.erase(data.begin() + index);
    } else {
        std::vector<std::string> subPath(path.begin() + 1, path.end());
        data[index]->delete_element(subPath);
    }
}

void JsonArray::move(const std::vector<std::string>& fromPath, const std::vector<std::string>& toPath) {
    if (fromPath.empty()) {
        throw InvalidPathError("Invalid path");
    }

    int index = std::stoi(fromPath[0]);
    if (index < 0 || index >= data.size()) {
        throw InvalidPathError("Element not found");
    }

    if (fromPath.size() == 1) {
        JsonElement* movedElement = data[index];
        data.erase(data.begin() + index);
        if (!toPath.empty()) {
            throw InvalidPathError("Cannot add element to array at specified path");
        }
        add_element(movedElement);
    } else {
        data[index]->move(std::vector<std::string>(fromPath.begin() + 1, fromPath.end()), toPath);
    }
}
