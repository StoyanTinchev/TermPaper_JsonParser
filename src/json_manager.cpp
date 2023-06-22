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

