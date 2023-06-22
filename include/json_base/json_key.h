/**
 * @file json_key.h
 * @brief Definition of the JsonKey class.
 */

#ifndef JSON_KEY_H
#define JSON_KEY_H

#include <string>

/**
 * @class JsonKey
 * @brief A class representing a key in a JSON key-value pair.
 *
 * The JsonKey class encapsulates a string key used in a JSON object. The key can be obtained or modified
 * through accessor methods, and can be converted to a JSON-formatted string.
 */
class JsonKey {
private:
    std::string key; ///< The encapsulated JSON key.

public:
    /**
     * @brief Construct a new JsonKey object with a given key.
     * @param key The string to use as the key.
     */
    explicit JsonKey(const std::string &key) : key(key) {}

    /**
     * @brief Get the encapsulated key.
     * @return The encapsulated key.
     */
    std::string get_key() const { return key; }

    /**
     * @brief Set the encapsulated key.
     * @param newKey The new string to use as the key.
     */
    void set_key(const std::string &newKey) { key = newKey; }

    /**
     * @brief Convert the encapsulated key to a JSON-formatted string.
     * @return A JSON-formatted string representing the key.
     */
    std::string to_string() const {
        return "\"" + key + "\"";
    }
};

#endif // JSON_KEY_H
