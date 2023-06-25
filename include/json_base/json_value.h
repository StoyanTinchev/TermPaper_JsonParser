/**
 * @file json_value.h
 * @brief Definition of the JsonValue class.
 */

#ifndef JSON_VALUE_H
#define JSON_VALUE_H

#include <json_base/json_element.h>
#include <json_base/json_key.h>
#include <json_base/json_object.h>
#include <json_base/json_array.h>
#include <json_exceptions.h>
#include <vector>
#include <string>

/**
 * @brief Enum class defining the possible value types of a JSON element
 */
enum class ValueType {
    Null, Number, String, Bool, Object, Array
};

/**
 * @class JsonValue
 * @brief JSON Value class that implements JsonElement interface.
 *
 * JsonValue class represents a JSON value which could be of type: String, Number, Bool, Object or Array.
 */
class JsonValue : public JsonElement {
private:
    std::string stringValue;   ///< Holds value when JSON value is a string.
    double numberValue;        ///< Holds value when JSON value is a number.
    bool boolValue;            ///< Holds value when JSON value is a boolean.
    ValueType valueType;       ///< Enum indicating the type of the JSON value.
    JsonArray *arrayValue;     ///< Holds value when JSON value is an array.
    JsonObject *objectValue;   ///< Holds value when JSON value is an object.

public:
    /**
     * @brief Default constructor for JsonValue.
     */
    JsonValue();

    /**
     * @brief Constructor for creating a JsonValue of type string.
     * @param value The string value.
     */
    explicit JsonValue(const std::string &value);

    /**
     * @brief Constructor for creating a JsonValue of type number.
     * @param value The number value.
     */
    explicit JsonValue(double value);

    /**
     * @brief Constructor for creating a JsonValue of type bool.
     * @param value The bool value.
     */
    explicit JsonValue(bool value);

    /**
     * @brief Constructor for creating a JsonValue of type JsonArray.
     * @param value The JsonArray value.
     */
    explicit JsonValue(JsonArray *value);

    /**
     * @brief Constructor for creating a JsonValue of type JsonObject.
     * @param value The JsonObject value.
     */
    explicit JsonValue(JsonObject *value);

    /**
     * @brief Converts JsonValue to a string representation.
     * @return A JSON-formatted string representing the object.
     */
    std::string to_string() const override;

    /**
     * @brief Search for a key in JsonValue.
     * @param key The key to search for.
     * @return A vector of paths to the elements that contain the key.
     */
    std::vector<std::string> search(const std::string &key) override;

    /**
     * @brief Check if JsonValue contains a specific string value.
     * @param value The value to check for.
     * @return True if the value is found, false otherwise.
     */
    bool contains(const std::string &value) override;

    /**
     * @brief Sets a new value in a JsonValue using a path.
     * @param path The path to the element.
     * @param new_value The new value to set.
     */
    void set(const std::vector<std::string> &path, const std::string &new_value) override;

    /**
     * @brief Creates a new JsonValue using a path.
     * @param path The path to the new element.
     * @param value The value of the new element.
     */
    void create(const std::vector<std::string> &path, const std::string &value) override;

    /**
     * @brief Deletes an element in a JsonValue using a path.
     * @param path The path to the element to delete.
     */
    void delete_element(const std::vector<std::string> &path) override;

    /**
     * @brief Moves an element from one path to another.
     * @param fromPath The current path of the element.
     * @param toPath The new path for the element.
     */
    void move(const std::vector<std::string> &fromPath, const std::vector<std::string> &toPath) override;

};


#endif // JSON_VALUE_H
