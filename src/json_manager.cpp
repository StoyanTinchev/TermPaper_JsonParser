#include <iostream>
#include <json_manager.h>
#include <json_exceptions.h>

JsonManager::JsonManager() : root(nullptr), parser(nullptr) {}

JsonManager::~JsonManager() {
    delete root;
    delete parser;
}

void JsonManager::open(const std::string &filePath) {
    std::ifstream inFile(filePath);
    if (!inFile) {
        throw FileError("Failed to open file: " + filePath);
    }

    std::string jsonContent((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    inFile.close();

    delete parser;
    parser = new JsonParser(jsonContent);
    delete root;
    root = parser->parse();

    currentFilePath = filePath;
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

    outFile << root->to_string();
    outFile.close();

    currentFilePath = filePath;
    std::cout << "Successfully saved " << filePath << std::endl;
}

void JsonManager::exit() {
    delete root;
    root = nullptr;
    delete parser;
    parser = nullptr;
    currentFilePath.clear();
    std::cout << "Exiting the application." << std::endl;
    // todo note: Actual application exit should be handled by the environment.
}

bool JsonManager::validate() {
    try {
        parser->parse();
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

    std::cout << root->to_string() << std::endl;
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

void JsonManager::set(const std::vector<std::string> &path, const std::string &new_value) {
    if (root == nullptr) {
        throw InvalidPathError("No data to set");
    }

    root->set(path, new_value);
}
