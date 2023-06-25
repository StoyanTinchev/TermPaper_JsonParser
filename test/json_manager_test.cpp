#include <string>
#include <json_manager.h>
#include <map>
#include <vector>
#include <iostream>
#include <json_exceptions.h>

int test_validate(JsonManager* json_manager);
int test_search(JsonManager* json_manager);
int test_contains(JsonManager* json_manager);
int test_set(JsonManager* json_manager);
int test_create(JsonManager* json_manager);
int test_delete(JsonManager* json_manager);
int test_move(JsonManager* json_manager);

std::map<std::string, int (*)(JsonManager*)> test_suite;

int main(int argc, const char* argv[]) {
    std::string test_file(argv[1]);
    std::string test_to_run(argv[2]);

    test_suite["VALIDATE"] = test_validate;
    test_suite["SEARCH"] = test_search;
    test_suite["CONTAINS"] = test_contains;
    test_suite["SET"] = test_set;
    test_suite["CREATE"] = test_create;
    test_suite["DELETE"] = test_delete;
    test_suite["MOVE"] = test_move;

    JsonManager jsonManager;
    try{
        jsonManager.open(test_file);
    } catch(JsonException& exception) {
        return -1;
    }

    int result = test_suite[test_to_run](&jsonManager);

    jsonManager.close();

    return result;
}

int test_validate(JsonManager* json_manager) {
    bool res = json_manager -> validate();
    
    if (res)
        return 0;
    
    return -1;
}

int test_search(JsonManager* json_manager) {
    std::string existing_key = "nice";
    std::vector<std::string> result = json_manager -> search(existing_key);

    if ((result.size() != 1) || (result[0] != "\"appropriate\"")) 
        return -1;
    
    std::string non_existing_key = "non-existent-key";
    result = json_manager -> search(non_existing_key);

    if (!result.empty())
        return -1;

    return 0;
}

int test_contains(JsonManager* json_manager) {
    std::string existing = "appropriate";
    std::string non_existing = "non-existent";

    bool res_existing = json_manager -> contains(existing);
    bool res_non_existing = json_manager -> contains(non_existing);
    
    if ((!res_existing) || (res_non_existing))
        return -1;

    return 0;
}       

int test_set(JsonManager* json_manager) {
    std::string key_to_set = "nice";
    std::string new_value = "new_value";

    json_manager -> set(key_to_set, new_value);

    std::vector<std::string> result = json_manager -> search(key_to_set);

    if ((result.size() != 1) || (result[0] != "\"new_value\"")) 
        return -1;

    return 0;
}

int test_create(JsonManager* json_manager) {
    std::string new_key_path = "new_key";
    std::string new_value = "new_value";

    json_manager -> create(new_key_path, new_value);

    std::vector<std::string> result = json_manager -> search(new_key_path);

    if ((result.size() != 1) || (result[0] != "\"" + new_value + "\"")) 
        return -1;

    return 0;
}

int test_delete(JsonManager* json_manager) {
    std::string key_to_delete = "special";

    json_manager -> delete_element(key_to_delete);

    std::vector<std::string> result = json_manager -> search(key_to_delete);

    if (!result.empty()) 
        return -1;

    return 0;
}

int test_move(JsonManager* json_manager) {
    std::string old_path = "special";
    std::string new_path = "not_special";

    json_manager -> move(old_path, new_path);

    std::vector<std::string> result = json_manager -> search(new_path);

    if ((result.size() != 1) || (result[0] != "false")) {
        std::cout << "in search" << std::endl;
        return -1;
    }
    
    return 0;
}
