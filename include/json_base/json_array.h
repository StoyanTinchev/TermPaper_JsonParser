#ifndef JSON_ARRAY_H
#define JSON_ARRAY_H

#include "json_element.h"
#include <vector>

class JsonArray : public JsonElement {
private:
    std::vector<JsonElement *> data;
public:
    JsonArray();

    ~JsonArray() override;

    void add_element(JsonElement *value);

    JsonElement *get_element(int index);

    std::string to_string() const override;

    std::vector<std::string> search(const std::string &key) override;

    bool contains(const std::string &value) override;

    void set(const std::vector<std::string> &path, const std::string &new_value) override;
};

#endif // JSON_ARRAY_H
