/**
 * @file json_parser.h
 * @brief Definition of the JsonParser class.
 */

#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <string>
#include <sstream>
#include <json_base/json_value.h>
#include <cctype>
#include <stdexcept>
#include <json_base/json_element.h>
#include <json_base/json_array.h>
#include <json_base/json_object.h>
#include <json_validator.h>

/**
 * @brief This class is responsible for parsing JSON text.
 *
 * It reads a string of JSON text and constructs an in-memory representation of the JSON
 * using `JsonValue`, `JsonArray`, and `JsonObject` objects. The parsing process includes
 * validation of the JSON text structure according to the JSON standard.
 */
class JsonParser {
private:
    std::string jsonStream; /**< @brief JSON text to parse */
    size_t position; /**< @brief Current position in the JSON text */

    /**
     * @brief Skips whitespace characters in the JSON text.
     */
    void skipWhitespace();

    /**
     * @brief Parses a number value from the JSON text.
     *
     * @return The parsed number as a double.
     */
    double parseNumber();

    /**
     * @brief Parses a string value from the JSON text.
     *
     * @return The parsed string.
     */
    std::string parseString();

    /**
     * @brief Parses a boolean value from the JSON text.
     *
     * @return The parsed boolean.
     */
    bool parseBool();

    /**
     * @brief Parses an array value from the JSON text.
     *
     * @return A pointer to the parsed `JsonArray` object.
     */
    JsonArray *parseArray();

    /**
     * @brief Parses an object value from the JSON text.
     *
     * @return A pointer to the parsed `JsonObject` object.
     */
    JsonObject *parseObject();

public:
    /**
     * @brief Validates the JSON text structure.
     *
     * Uses the `JsonValidator` class to ensure that the JSON text has a valid structure.
     */
    void validate();
    
    /**
     * @brief Constructs a new Json Parser object.
     *
     * @param jsonStream The JSON text to parse.
     */
    explicit JsonParser(const std::string &jsonStream);

    /**
     * @brief Begins parsing the JSON text.
     *
     * @return A pointer to the root `JsonElement` object representing the parsed JSON.
     */
    JsonElement *parse();
};

#endif // JSON_PARSER_H
