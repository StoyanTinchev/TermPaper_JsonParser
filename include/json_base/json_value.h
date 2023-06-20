#ifndef JSON_VALUE_H
#define JSON_VALUE_H

#include "json_element.h"
#include "json_key.h"
#include "json_object.h"
#include "json_array.h"
#include <vector>
#include <string>

enum class ValueType {
    Null, Number, String, Bool, Object, Array
};

class JsonValue : public JsonElement {
private:
    std::string stringValue;
    double numberValue;
    bool boolValue;
    ValueType valueType;
    JsonArray *arrayValue;
    JsonObject *objectValue;
public:
    JsonValue();

    explicit JsonValue(const std::string &value);

    explicit JsonValue(double value);

    explicit JsonValue(bool value);

    explicit JsonValue(JsonArray *value);

    explicit JsonValue(JsonObject *value);

    std::string to_string() const override;
};


#endif // JSON_VALUE_H
