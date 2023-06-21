#ifndef JSON_ELEMENT_H
#define JSON_ELEMENT_H

#include <string>
#include <vector>

class JsonElement {
public:
    virtual ~JsonElement() = default;

    virtual std::string to_string() const = 0;

    virtual std::vector<std::string> search(const std::string &key) = 0;

    virtual bool contains(const std::string &value) = 0;

    virtual void set(const std::vector<std::string> &path, const std::string &new_value) = 0;
};

#endif // JSON_ELEMENT_H
