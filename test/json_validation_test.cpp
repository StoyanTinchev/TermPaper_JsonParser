#include <fstream>
#include <sstream>
#include <iostream>
#include <json_validator.h>
#include <cstring>

const std::string fetch_json(const char* filename);

int main(int argc, char* argv[]) {
    const std::string str = fetch_json(argv[1]);
    if(str == "") return -1;

    if (!strcmp(argv[2], "VALID")) {
        return !JsonValidator::validate(str);
    } else if (!strcmp(argv[2], "INVALID")) {
        return JsonValidator::validate(str);
    } else {
        return -1;
    }
}

const std::string fetch_json(const char* filename) {
    std::ifstream input_json;
    input_json.open(filename);

    if (!input_json.is_open()) {
        std::cout << "Error opening the JSON file." << std::endl;
        return "";
    }

    std::ostringstream output;

    output << input_json.rdbuf();
    return (const std::string) output.str();
}
