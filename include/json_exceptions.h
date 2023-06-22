/**
 * @file json_exceptions.h
 * @brief Definition of the custom exceptions used in the JSON library.
 */

#ifndef JSON_EXCEPTIONS_H
#define JSON_EXCEPTIONS_H

#include <stdexcept>
#include <string>

/**
 * @brief Base class for exceptions related to JSON processing.
 *
 * This class inherits from the std::runtime_error class and serves as the base class for all custom exceptions in the JSON library.
 */
class JsonException : public std::runtime_error {
public:
    explicit JsonException(const std::string &msg) : std::runtime_error(msg) {}
};

/**
 * @brief Exception indicating an invalid JSON format.
 *
 * This exception is thrown when an attempt to parse a string as a JSON document fails due to invalid syntax.
 */
class InvalidJsonFormat : public JsonException {
public:
    explicit InvalidJsonFormat(const std::string &msg = "Invalid JSON format")
            : JsonException(msg) {}
};

/**
 * @brief Exception indicating an invalid boolean value in a JSON document.
 *
 * This exception is thrown when an attempt to parse a boolean value in a JSON document fails because the value is not 'true' or 'false'.
 */
class InvalidBooleanValue : public JsonException {
public:
    explicit InvalidBooleanValue(const std::string &msg = "Invalid boolean value in Json")
            : JsonException(msg) {}
};

/**
 * @brief Exception indicating invalid array syntax in a JSON document.
 *
 * This exception is thrown when an attempt to parse an array in a JSON document fails due to invalid syntax.
 */
class InvalidArraySyntax : public JsonException {
public:
    explicit InvalidArraySyntax(const std::string &msg = "Invalid array syntax in Json")
            : JsonException(msg) {}
};

/**
 * @brief Exception indicating invalid object syntax in a JSON document.
 *
 * This exception is thrown when an attempt to parse an object in a JSON document fails due to invalid syntax.
 */
class InvalidObjectSyntax : public JsonException {
public:
    explicit InvalidObjectSyntax(const std::string &msg = "Invalid object syntax in Json")
            : JsonException(msg) {}
};

/**
 * @brief Exception indicating an unexpected token in a JSON document.
 *
 * This exception is thrown when an unexpected token is encountered while parsing a JSON document.
 */
class UnexpectedToken : public JsonException {
public:
    explicit UnexpectedToken(const std::string &msg = "Unexpected token in Json")
            : JsonException(msg) {}
};

/**
 * @brief Exception indicating a file error.
 *
 * This exception is thrown when a file operation (such as opening a file) fails.
 */
class FileError : public JsonException {
public:
    explicit FileError(const std::string &msg = "File error")
            : JsonException(msg) {}
};

/**
 * @brief Exception indicating an invalid path in a JSON document.
 *
 * This exception is thrown when an invalid path is provided for operations that require a path in a JSON document.
 */
class InvalidPathError : public JsonException {
public:
    explicit InvalidPathError(const std::string &msg = "Invalid path provided")
            : JsonException(msg) {}
};

/**
 * @brief Exception indicating that a specified element was not found in a JSON document.
 *
 * This exception is thrown when an operation attempts to access an element that does not exist in the JSON document.
 */
class ElementNotFoundError : public JsonException {
public:
    explicit ElementNotFoundError(const std::string &msg = "Specified element not found")
            : JsonException(msg) {}
};

/**
 * @brief Exception indicating that a specified element already exists in a JSON document.
 *
 * This exception is thrown when an operation attempts to create an element that already exists at the specified location in the JSON document.
 */
class ElementAlreadyExistsError : public JsonException {
public:
    explicit ElementAlreadyExistsError(const std::string &msg = "Specified element already exists")
            : JsonException(msg) {}
};

#endif // JSON_EXCEPTIONS_H
