#ifndef JSON_ELEMENT_H
#define JSON_ELEMENT_H

#include <string>

class JsonElement {
public:
    virtual ~JsonElement() = default;

    virtual std::string to_string() const = 0;
};

#endif // JSON_ELEMENT_H
