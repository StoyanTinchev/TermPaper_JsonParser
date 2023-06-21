#ifndef JSON_MANAGER_H
#define JSON_MANAGER_H

#include <string>
#include <fstream>
#include <regex>
#include "json_parser.h"

class JsonManager {
private:
    std::string currentFilePath;
    JsonElement *root;
    JsonParser *parser;

public:
    JsonManager();

    ~JsonManager();

    void open(const std::string &filePath);

    void save();

    void saveAs(const std::string &filePath);

    void exit();

    bool validate();

    void print();

    std::vector<std::string> search(const std::string &key);

    bool contains(const std::string &value);

    void set(const std::vector<std::string> &path, const std::string &new_value);
};

#endif // JSON_MANAGER_H
