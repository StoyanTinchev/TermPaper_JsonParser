/**
 * @file json_array.h
 * @brief Definition of the JsonArray class.
 */

#ifndef JSON_ARRAY_H
#define JSON_ARRAY_H

#include <json_base/json_element.h>
#include <vector>
#include "json_exceptions.h"

/**
 * @class JsonArray
 * @brief A class that represents an array in JSON.
 *
 * The JsonArray class encapsulates a vector of JsonElement pointers and provides methods
 * to manipulate and search the array, in addition to converting the array to a JSON-formatted string.
 */
class JsonArray : public JsonElement {
private:
    std::vector<JsonElement *> data; ///< Vector of JsonElement pointers that make up the array.

public:
    /**
     * @brief Default constructor for JsonArray.
     */
    JsonArray();

    /**
     * @brief Destructor for JsonArray, overridden from JsonElement.
     */
    ~JsonArray() override;

    /**
     * @brief Add an element to the array.
     * @param value The element to add.
     */
    void add_element(JsonElement *value);

    /**
     * @brief Get an element from the array by index.
     * @param index The index of the element to get.
     * @return The element at the given index.
     */
    JsonElement *get_element(int index);

    /**
     * @brief Convert the array to a JSON-formatted string.
     * @return A JSON-formatted string representing the array.
     */
    std::string to_string() const override;

    /**
     * @brief Search for a key in the array.
     * @param key The key to search for.
     * @return A vector of paths to the elements that contain the key.
     */
    std::vector<std::string> search(const std::string &key) override;

    /**
     * @brief Check if the array contains a value.
     * @param value The value to check for.
     * @return True if the value is found, false otherwise.
     */
    bool contains(const std::string &value) override;

    /**
     * @brief Set the value of an element at a given path.
     * @param path The path to the element.
     * @param new_value The new value to set.
     */
    void set(const std::vector<std::string> &path, const std::string &new_value) override;

    /**
     * @brief Create a new element at a given path.
     * @param path The path to the new element.
     * @param value The value of the new element.
     */
    void create(const std::vector<std::string> &path, const std::string &value) override;

    /**
     * @brief Delete an element at a given path.
     * @param path The path to the element to delete.
     */
    void delete_element(const std::vector<std::string> &path) override;

    /**
     * @brief Move an element from one path to another.
     * @param fromPath The current path of the element.
     * @param toPath The new path for the element.
     */
    void move(const std::vector<std::string> &fromPath, const std::vector<std::string> &toPath) override;

};

#endif // JSON_ARRAY_H
