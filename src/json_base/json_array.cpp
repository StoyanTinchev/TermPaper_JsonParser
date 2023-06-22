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
