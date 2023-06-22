/**
 * @file json_element.h
 * @brief Definition of the JsonElement class.
 */

#ifndef JSON_ELEMENT_H
#define JSON_ELEMENT_H

#include <string>
#include <vector>

/**
 * @class JsonElement
 * @brief An abstract class representing an element in a JSON document.
 *
 * JsonElement is a base class for all types of elements that can appear in a JSON document, such as
 * arrays, objects, and primitive values (strings, numbers, booleans, null).
 * It provides a common interface for operations that can be performed on any JSON element, such as
 * converting it to a string, searching for a key, checking for the presence of a value, and modifying
 * its contents.
 */
class JsonElement {
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~JsonElement() = default;

    /**
     * @brief Convert the JSON element to a string.
     * @return A string representation of the JSON element.
     */
    virtual std::string to_string() const = 0;

    /**
     * @brief Search for a key in the JSON element.
     * @param key The key to search for.
     * @return A vector of strings representing the path to the key, or an empty vector if the key is not found.
     */
    virtual std::vector<std::string> search(const std::string &key) = 0;

    /**
     * @brief Check if the JSON element contains a certain value.
     * @param value The value to check for.
     * @return True if the value is found, false otherwise.
     */
    virtual bool contains(const std::string &value) = 0;

    /**
     * @brief Set the value at a certain path in the JSON element.
     * @param path A vector of strings representing the path to the value.
     * @param new_value The new value to set.
     */
    virtual void set(const std::vector<std::string> &path, const std::string &new_value) = 0;

    /**
     * @brief Create a new key-value pair at a certain path in the JSON element.
     * @param path A vector of strings representing the path to the new key-value pair.
     * @param value The value to set for the new key.
     */
    virtual void create(const std::vector<std::string> &path, const std::string &value) = 0;

    /**
     * @brief Delete a key-value pair at a certain path in the JSON element.
     * @param path A vector of strings representing the path to the key-value pair to delete.
     */
    virtual void delete_element(const std::vector<std::string> &path) = 0;

    /**
     * @brief Move a key-value pair from one path to another in the JSON element.
     * @param fromPath A vector of strings representing the current path of the key-value pair.
     * @param toPath A vector of strings representing the new path for the key-value pair.
     */
    virtual void move(const std::vector<std::string> &fromPath, const std::vector<std::string> &toPath) = 0;
};

#endif // JSON_ELEMENT_H
