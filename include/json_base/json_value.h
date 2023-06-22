#ifndef JSON_VALUE_H
#define JSON_VALUE_H

#include <json_base/json_element.h>
#include <json_base/json_key.h>
#include <json_base/json_object.h>
#include <json_base/json_array.h>
#include <json_exceptions.h>
#include <vector>
#include <string>

enum class ValueType {
    Number, String, Bool, Object, Array
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

    std::vector<std::string> search(const std::string &key) override;

    bool contains(const std::string &value) override;

    void set(const std::vector<std::string> &path, const std::string &new_value) override;
};


#endif // JSON_VALUE_H
