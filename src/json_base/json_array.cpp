#include "../../include/json_base/json_array.h"

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
    if (index >= 0 && index < data.size()) {
        return data[index];
    }
    return nullptr;
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
