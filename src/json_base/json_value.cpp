#include <stdexcept>
#include "../../include/json_base/json_value.h"

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
        case ValueType::Null:
            result = "null";
            break;
        default:
            throw std::runtime_error("Invalid value type");
    }
    return result;
}

