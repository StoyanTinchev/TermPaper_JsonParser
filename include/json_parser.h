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

    void validate() {
        if (!JsonValidator::validate(jsonStream)) {
            throw std::runtime_error("Invalid JSON format");
        }
    }

    void skipWhitespace() {
        while (position < jsonStream.size() && std::isspace(jsonStream[position])) {
            position++;
        }
    }

    double parseNumber();

    std::string parseString();

    bool parseBool();

    JsonArray *parseArray();

    JsonObject *parseObject();

public:
    explicit JsonParser(const std::string &jsonStream) : jsonStream(jsonStream), position(0) {
        validate();
    }

    JsonElement *parse();
};;

#endif // JSON_PARSER_H
