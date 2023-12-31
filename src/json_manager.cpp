#include <iostream>
#include <json_manager.h>
#include <json_exceptions.h>

JsonManager::JsonManager() : root(nullptr), parser(nullptr), jsonOpened(false) {}

JsonManager::~JsonManager() {
    delete root;
    delete parser;
}

void JsonManager::open(const std::string &filePath) {
    if (jsonOpened)
        throw FileError("A JSON file is already opened for processing.");

    std::ifstream inFile(filePath);
    if (!inFile) {
        throw FileError("Failed to open file: " + filePath);
    }

    std::string jsonContent((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    inFile.close();

    parser = new JsonParser(jsonContent);
    root = parser->parse();

    currentFilePath = filePath;
    jsonOpened = true;
    std::cout << "Successfully opened " << filePath << std::endl;
}

void JsonManager::save() {
    if (currentFilePath.empty()) {
        throw FileError("No file is currently open");
    }
    saveAs(currentFilePath);
}

void JsonManager::saveAs(const std::string &filePath) {
    if (!root) {
        throw InvalidPathError("No data to save");
    }

    std::ofstream outFile(filePath);
    if (!outFile) {
        throw FileError("Failed to open file: " + filePath);
    }

    outFile << JsonWhitespaceFormatter::format(root -> to_string());
    outFile.close();

    currentFilePath = filePath;
    std::cout << "Successfully saved " << filePath << std::endl;
}

void JsonManager::close() {
    if (!jsonOpened) 
        throw FileError("No JSON file is opened for processing.");

    delete root;
    root = nullptr;
    delete parser;
    parser = nullptr;
    jsonOpened = false;
    std::cout << "Successfully closed " << currentFilePath << std::endl;
    currentFilePath = "";
}

bool JsonManager::validate() {
    try {
        parser->validate();
        return true;
    } catch (const JsonException &ex) {
        std::cerr << "JSON file is not valid: " << ex.what() << std::endl;
        return false;
    }
}

void JsonManager::print() {
    if (root == nullptr) {
        throw InvalidPathError("No data to print");
    }

    std::cout << JsonWhitespaceFormatter::format(root -> to_string()) << std::endl;
}

std::vector<std::string> JsonManager::search(const std::string &key) {
    if (root == nullptr) {
        throw InvalidPathError("No data to search");
    }

    return root->search(key);
}

bool JsonManager::contains(const std::string &value) {
    if (root == nullptr) {
        throw InvalidPathError("No data to search");
    }

    return root->contains(value);
}

void JsonManager::set(const std::string &path, const std::string &new_value) {
    std::vector<std::string> splitPath = split(path, '.');

    if (!root) {
        throw ElementNotFoundError("Root element not found");
    }

    root->set(splitPath, new_value);
}

void JsonManager::create(const std::string &path, const std::string &value) {
    std::vector<std::string> splitPath = split(path, '.');

    if (!root) {
        throw ElementNotFoundError("Root element not found");
    }

    root->create(splitPath, value);
}

std::vector<std::string> JsonManager::split(const std::string &str, char delimiter) {
    std::vector<std::string> result;
    std::istringstream iss(str);
    for (std::string token; std::getline(iss, token, delimiter);) {
        result.push_back(std::move(token));
    }
    return result;
}

void JsonManager::delete_element(const std::string &path) {
    std::vector<std::string> splitPath = split(path, '.');

    if (splitPath.empty()) {
        throw InvalidPathError("Path cannot be empty");
    }

    root->delete_element(splitPath);
}

void JsonManager::move(const std::string &fromPath, const std::string &toPath) {
    std::vector<std::string> splitFromPath = split(fromPath, '.');
    std::vector<std::string> splitToPath = split(toPath, '.');

    if (splitFromPath.empty() || splitToPath.empty()) {
        throw InvalidPathError("Path cannot be empty");
    }

    root->move(splitFromPath, splitToPath);
}

