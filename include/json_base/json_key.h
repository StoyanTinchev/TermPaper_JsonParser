#ifndef JSON_KEY_H
#define JSON_KEY_H

#include <string>

class JsonKey {
private:
    std::string key;
public:
    explicit JsonKey(const std::string &key) : key(key) {}

    std::string get_key() const { return key; }

    void set_key(const std::string &newKey) { key = newKey; }

    std::string to_string() const {
        return "\"" + key + "\"";
    }
};

#endif // JSON_KEY_H
