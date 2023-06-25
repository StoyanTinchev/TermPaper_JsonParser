/**
 * @file json_whitespace_formatter.h
 * @brief Defines a class that restores whitespace character whereever needed.
*/

#ifndef JSON_FORMATTER_H
#define JSON_FORMATTER_H

#include <string>

/**
 * @class JsonWhitespaceFormatter
 * @brief Class that restores whitespace characters.
 * 
 * The class has a static function "format" that accepts a string representation of a JSON 
 * structure with no whitespace characters, and adds those characters whereever needed.
*/
class JsonWhitespaceFormatter {
    public: 
        /**
         * @brief Restores whitespace characters.
         * @param unformatted_output The unformatted string representation of a JSON structure.
         * @returns A string formatted with whitespace characters.
        */
        static std::string format(const std::string &unformatted_output);
};

#endif //JSON_FORMATTER_H