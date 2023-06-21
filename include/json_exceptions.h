#ifndef JSON_EXCEPTIONS_H
#define JSON_EXCEPTIONS_H

#include <stdexcept>
#include <string>

class JsonException : public std::runtime_error {
public:
    explicit JsonException(const std::string &msg) : std::runtime_error(msg) {}
};

class InvalidJsonFormat : public JsonException {
public:
    explicit InvalidJsonFormat(const std::string &msg = "Invalid JSON format")
            : JsonException(msg) {}
};

class InvalidBooleanValue : public JsonException {
public:
    explicit InvalidBooleanValue(const std::string &msg = "Invalid boolean value in Json")
            : JsonException(msg) {}
};

class InvalidArraySyntax : public JsonException {
public:
    explicit InvalidArraySyntax(const std::string &msg = "Invalid array syntax in Json")
            : JsonException(msg) {}
};

class InvalidObjectSyntax : public JsonException {
public:
    explicit InvalidObjectSyntax(const std::string &msg = "Invalid object syntax in Json")
            : JsonException(msg) {}
};

class UnexpectedToken : public JsonException {
public:
    explicit UnexpectedToken(const std::string &msg = "Unexpected token in Json")
            : JsonException(msg) {}
};

class FileError : public JsonException {
public:
    explicit FileError(const std::string &msg = "File error")
            : JsonException(msg) {}
};

class InvalidPathError : public JsonException {
public:
    explicit InvalidPathError(const std::string &msg = "Invalid path provided")
            : JsonException(msg) {}
};

class ElementNotFoundError : public JsonException {
public:
    explicit ElementNotFoundError(const std::string &msg = "Specified element not found")
            : JsonException(msg) {}
};

class ElementAlreadyExistsError : public JsonException {
public:
    explicit ElementAlreadyExistsError(const std::string &msg = "Specified element already exists")
            : JsonException(msg) {}
};

#endif // JSON_EXCEPTIONS_H
