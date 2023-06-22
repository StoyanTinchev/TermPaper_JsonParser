/**
 * @file json_object.h
 * @brief Definition of the JsonObject class.
 */

#ifndef JSON_OBJECT_H
#define JSON_OBJECT_H

#include <json_base/json_element.h>
#include <json_base/json_key.h>
#include <vector>

/**
 * @class JsonObject
 * @brief A class that represents an object in JSON.
 *
 * The JsonObject class encapsulates a vector of key-value pairs where the key is a JsonKey pointer
 * and the value is a JsonElement pointer. The class provides methods to manipulate, search,
 * and convert the object to a JSON-formatted string.
 */
class JsonObject : public JsonElement {
private:
    std::vector<std::pair<JsonKey *, JsonElement *>> data; ///< Vector of key-value pairs that make up the object.

    /**
     * @brief Finds an element in the object using a given key.
     * @param key The key associated with the element to find.
     * @return An iterator to the key-value pair, if found. Otherwise, it returns an iterator to the end of the data vector.
     */
    std::vector<std::pair<JsonKey *, JsonElement *>>::iterator find_element(const std::string &key);

public:
    /**
     * @brief Default constructor for JsonObject.
     */
    JsonObject();

    /**
     * @brief Destructor for JsonObject, overridden from JsonElement.
     */
    ~JsonObject() override;

    /**
     * @brief Add a key-value pair to the object.
     * @param key The key to add.
     * @param value The value to add.
     */
    void add_element(JsonKey *key, JsonElement *value);

    /**
     * @brief Get the value associated with a given key in the object.
     * @param key The key associated with the value to get.
     * @return The value associated with the given key.
     */
    JsonElement *get_element(const std::string &key);

    /**
     * @brief Convert the object to a JSON-formatted string.
     * @return A JSON-formatted string representing the object.
     */
    std::string to_string() const override;

    /**
     * @brief Search for a key in the object.
     * @param key The key to search for.
     * @return A vector of paths to the elements that contain the key.
     */
    std::vector<std::string> search(const std::string &key) override;

    /**
     * @brief Check if the object contains a value.
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

#endif // JSON_OBJECT_H
