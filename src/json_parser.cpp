#include <sstream>
#include "../include/json_parser.h"

double JsonParser::parseNumber() {
    size_t endPos;
    double value = std::stod(jsonStream.substr(position), &endPos);
    position += endPos;
    return value;
}

std::string JsonParser::parseString() {
    std::stringstream ss;

    position++;

    while (position < jsonStream.size() && jsonStream[position] != '\"') {
        ss << jsonStream[position++];
    }

    if (position < jsonStream.size()) {
        position++;
    }

    return ss.str();
}

bool JsonParser::parseBool() {
    if (jsonStream.substr(position, 4) == "true") {
        position += 4;
        return true;
    } else if (jsonStream.substr(position, 5) == "false") {
        position += 5;
        return false;
    }

    throw std::runtime_error("Invalid boolean value");
}

JsonArray *JsonParser::parseArray() {
    JsonArray *array = new JsonArray();

    position++;
    skipWhitespace();

    while (position < jsonStream.size() && jsonStream[position] != ']') {
        array->add_element(parse());
        skipWhitespace();

        if (jsonStream[position] == ',') {
            position++;
            skipWhitespace();
        }
    }

    if (position >= jsonStream.size() || jsonStream[position] != ']') {
        throw std::runtime_error("Invalid array syntax");
    }

    position++;
    return array;
}

JsonObject *JsonParser::parseObject() {
    JsonObject *object = new JsonObject();
    position++;
    skipWhitespace();

    while (position < jsonStream.size() && jsonStream[position] != '}') {
        JsonKey *key = new JsonKey(parseString());
        skipWhitespace();

        if (position >= jsonStream.size() || jsonStream[position] != ':') {
            throw std::runtime_error("Invalid object syntax");
        }

        position++;
        skipWhitespace();

        JsonElement *value = parse();
        object->add_element(key, value);
        skipWhitespace();

        if (jsonStream[position] == ',') {
            position++;
            skipWhitespace();
        }
    }

    if (position >= jsonStream.size() || jsonStream[position] != '}') {
        throw std::runtime_error("Invalid object syntax");
    }

    position++;
    return object;
}

JsonElement *JsonParser::parse() {
    skipWhitespace();
    switch (jsonStream[position]) {
        case '[':
            return parseArray();
        case '{':
            return parseObject();
        case '\"':
            return new JsonValue(parseString());
        case 't':
        case 'f':
            return new JsonValue(parseBool());
        default:
            if ((jsonStream[position] >= '0' && jsonStream[position] <= '9') || jsonStream[position] == '-') {
                return new JsonValue(parseNumber());
            }

            if (jsonStream.substr(position, 4) == "null") {
                position += 4;
                return new JsonValue("");
            }

            throw std::runtime_error("Unexpected token");
    }
}

