#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <string>
#include <sstream>
#include "../include/json_base/json_value.h"
#include <cctype>
#include <stdexcept>
#include "json_base/json_element.h"
#include "json_base/json_array.h"
#include "json_base/json_object.h"
#include "json_validator.h"

class JsonParser {
private:
    std::string jsonStream;
    size_t position;

    void validate();

    void skipWhitespace();

    double parseNumber();

    std::string parseString();

    bool parseBool();

    JsonArray *parseArray();

    JsonObject *parseObject();

public:
    explicit JsonParser(const std::string &jsonStream);

    JsonElement *parse();
};;

#endif // JSON_PARSER_H
