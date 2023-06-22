/**
 * @file json_manager.h
 * @brief Defines the class that manages JSON operations
 */

#ifndef JSON_MANAGER_H
#define JSON_MANAGER_H

#include <string>
#include <fstream>
#include <regex>
#include <json_parser.h>

/**
 * @class JsonManager
 * @brief The JsonManager class provides functionalities to manage JSON operations.
 *
 * JsonManager uses a JsonParser to parse the JSON, and provides operations like opening, saving,
 * validating, printing, searching, checking containment, setting, creating, deleting, and moving elements within a JSON.
 */
class JsonManager {
private:
    std::string currentFilePath; /**< The current file path of the JSON file. */
    JsonElement *root; /**< The root of the JSON structure. */
    JsonParser *parser; /**< The JsonParser used to parse the JSON. */

    /**
     * @brief Splits a string by a delimiter.
     *
     * @param str The string to split.
     * @param delimiter The delimiter character.
     * @return A vector of strings which are split by the delimiter.
     */
    std::vector<std::string> split(const std::string &str, char delimiter);

public:
    /**
     * @brief Default constructor for JsonManager.
     */
    JsonManager();

    /**
     * @brief Destructor for JsonManager.
     */
    ~JsonManager();

    /**
     * @brief Opens a JSON file.
     *
     * @param filePath The path to the JSON file.
     */
    void open(const std::string &filePath);

    /**
     * @brief Saves the current JSON to the file path.
     */
    void save();

    /**
     * @brief Saves the current JSON to a new file path.
     *
     * @param filePath The new path to save the JSON file.
     */
    void saveAs(const std::string &filePath);

    /**
     * @brief Exits the JsonManager.
     */
    void exit();

    /**
     * @brief Validates the JSON file.
     *
     * @return true if the JSON file is valid, false otherwise.
     */
    bool validate();

    /**
     * @brief Prints the JSON to the console.
     */
    void print();

    /**
     * @brief Searches the JSON for a key.
     *
     * @param key The key to search for.
     * @return A vector of strings with the path to the key.
     */
    std::vector<std::string> search(const std::string &key);

    /**
     * @brief Checks if the JSON contains a value.
     *
     * @param value The value to check for.
     * @return true if the JSON contains the value, false otherwise.
     */
    bool contains(const std::string &value);

    /**
     * @brief Sets a value in the JSON.
     *
     * @param path The path to the value to set.
     * @param new_value The new value to set.
     */
    void set(const std::string &path, const std::string &new_value);

    /**
     * @brief Creates a new key-value pair in the JSON.
     *
     * @param path The path to the place to create the new key-value pair.
     * @param value The value of the new key-value pair.
     */
    void create(const std::string &path, const std::string &value);

    /**
     * @brief Deletes an element in the JSON.
     *
     * @param path The path to the element to delete.
     */
    void delete_element(const std::string &path);

    /**
     * @brief Moves an element from one location to another in the JSON.
     *
     * @param fromPath The path to the element to move.
     * @param toPath The path to the new location for the element.
     */
    void move(const std::string &fromPath, const std::string &toPath);
};

#endif // JSON_MANAGER_H

