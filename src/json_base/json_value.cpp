#include <stdexcept>
#include "../../include/json_base/json_value.h"
#include "../../include/json_exceptions.h"

JsonValue::JsonValue() : valueType(ValueType::Null) {}

JsonValue::JsonValue(const std::string &value)
        : stringValue(value), valueType(ValueType::String) {}

JsonValue::JsonValue(double value)
        : numberValue(value), valueType(ValueType::Number) {}

JsonValue::JsonValue(bool value)
        : boolValue(value), valueType(ValueType::Bool) {}

JsonValue::JsonValue(JsonArray *value)
        : valueType(ValueType::Array), arrayValue(value) {}

JsonValue::JsonValue(JsonObject *value)
        : valueType(ValueType::Object), objectValue(value) {}

std::string JsonValue::to_string() const {
    std::string result;
    switch (valueType) {
        case ValueType::String:
            result = "\"" + stringValue + "\"";
            break;
        case ValueType::Number:
            result = std::to_string(numberValue);
            break;
        case ValueType::Bool:
            result = boolValue ? "true" : "false";
            break;
        case ValueType::Object:
            result = objectValue->to_string();
            break;
        case ValueType::Array:
            result = arrayValue->to_string();
            break;
        default:
            throw JsonException("Invalid JSON value type.");;
    }
    return result;
}

std::vector<std::string> JsonValue::search(const std::string &key) {
    std::vector<std::string> results;
    switch (valueType) {
        case ValueType::String:
            if (stringValue == key) {
                results.push_back(to_string());
            }
            break;
        case ValueType::Number:
            if (std::to_string(numberValue) == key) {
                results.push_back(to_string());
            }
            break;
        case ValueType::Bool:
            if (std::to_string(boolValue) == key) {
                results.push_back(to_string());
            }
            break;
        case ValueType::Object:
            if (objectValue != nullptr) {
                results = objectValue->search(key);
            }
            break;
        case ValueType::Array:
            if (arrayValue != nullptr) {
                results = arrayValue->search(key);
            }
            break;
        default:
            break;
    }
    return results;
}

bool JsonValue::contains(const std::string &value) {
    bool result = false;
    switch (valueType) {
        case ValueType::String:
            result = stringValue == value;
            break;
        case ValueType::Number:
            result = std::to_string(numberValue) == value;
            break;
        case ValueType::Bool:
            result = std::to_string(boolValue) == value;
            break;
        case ValueType::Object:
            if (objectValue != nullptr) {
                result = objectValue->contains(value);
            }
            break;
        case ValueType::Array:
            if (arrayValue != nullptr) {
                result = arrayValue->contains(value);
            }
            break;
        default:
            break;
    }
    return result;
}


void JsonValue::set(const std::vector<std::string> &path, const std::string &new_value) {
    if (path.empty()) {
        throw InvalidPathError("Path cannot be empty when setting a value");
    }

    switch (valueType) {
        case ValueType::String:
            if (path.size() == 1 && path[0] == stringValue) {
                stringValue = new_value;
            }
            break;
        case ValueType::Number:
            if (path.size() == 1 && path[0] == std::to_string(numberValue)) {
                numberValue = std::stod(new_value);
            }
            break;
        case ValueType::Bool:
            if (path.size() == 1 && path[0] == std::to_string(boolValue)) {
                boolValue = new_value == "true";
            }
            break;
        case ValueType::Object:
            if (objectValue != nullptr) {
                objectValue->set(path, new_value);
            }
            break;
        case ValueType::Array:
            if (arrayValue != nullptr) {
                arrayValue->set(path, new_value);
            }
            break;
        default:
            throw InvalidPathError("Cannot set a value in a non-object or non-array JSON value");
    }
}
