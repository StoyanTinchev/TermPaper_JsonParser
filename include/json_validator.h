/**
 * @file json_validator.h
 * @brief Defines a class used to validate JSON strings
 */

#ifndef JSON_VALIDATOR_H
#define JSON_VALIDATOR_H

#include <string>
#include <stack>
#include <cctype>

/**
 * @class JsonValidator
 * @brief The JsonValidator class validates a string to check if it's a correctly formed JSON.
 *
 * JsonValidator has a static method validate() that checks if the given string forms a valid JSON.
 */
class JsonValidator {
public:
    /**
     * @brief Validates a JSON string.
     *
     * This static method validates a string to see if it's a correctly formatted JSON. It checks for correctly
     * paired brackets (both square and curly), correct usage of double quotes for strings, and ignores characters
     * within strings.
     *
     * @param json The JSON string to validate.
     * @return true if the string is a valid JSON, false otherwise.
     */
    static bool validate(const std::string &json) {
        std::stack<char> brackets;
        bool in_quotes = false;
        bool escaped = false;
        for (char c: json) {
            if (c == '\\') {
                escaped = !escaped;
                continue;
            }
            if (c == '"' && !escaped) {
                in_quotes = !in_quotes;
            } else if (!in_quotes) {
                switch (c) {
                    case '{':
                    case '[':
                        brackets.push(c);
                        break;
                    case '}':
                        if (brackets.empty() || brackets.top() != '{') {
                            return false;
                        }
                        brackets.pop();
                        break;
                    case ']':
                        if (brackets.empty() || brackets.top() != '[') {
                            return false;
                        }
                        brackets.pop();
                        break;
                }
            }
            if (escaped) {
                escaped = false;
            }
        }
        return brackets.empty() && !in_quotes;
    }
};

#endif // JSON_VALIDATOR_H
