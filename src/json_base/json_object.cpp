#include "../../include/json_base/json_object.h"

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
    return nullptr;
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