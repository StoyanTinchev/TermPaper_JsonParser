#ifndef JSON_OBJECT_H
#define JSON_OBJECT_H

#include "json_element.h"
#include "json_key.h"
#include <vector>

class JsonObject : public JsonElement {
private:
    std::vector<std::pair<JsonKey *, JsonElement *>> data;
public:
    JsonObject();

    ~JsonObject() override;

    void add_element(JsonKey *key, JsonElement *value);

    JsonElement *get_element(const std::string &key);

    std::string to_string() const override;
};

#endif // JSON_OBJECT_H
