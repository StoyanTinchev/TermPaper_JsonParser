#include <cmd_interpreter/command.h>
#include <iostream>
#include <json_whitespace_formatter.h>

bool ValidateCommand::validate(std::vector<std::string> tokenized_cmd) {
    if ((tokenized_cmd.size() == 1) && (tokenized_cmd[0] == getName()))
        return true;

    return false;
}

bool ValidateCommand::execute(std::vector<std::string> tokenized_cmd) {
    if (!validate(tokenized_cmd))
        return false;

    JsonManager* json_manager = getJsonManager();
    if (json_manager -> validate()) 
        std::cout << "The JSON file is valid." << std::endl;

    return true; 
}

bool PrintCommand::validate(std::vector<std::string> tokenized_cmd) {
    if ((tokenized_cmd.size() == 1) && (tokenized_cmd[0] == getName()))
        return true;

    return false;
}

bool PrintCommand::execute(std::vector<std::string> tokenized_cmd) {
    if (!validate(tokenized_cmd))
        return false;

    JsonManager* json_manager = getJsonManager();
    json_manager -> print();
    return true;
}

bool OpenCommand::validate(std::vector<std::string> tokenized_cmd) {
    if ((tokenized_cmd.size() != 2) || (tokenized_cmd[0] != getName()))
        return false;

    return true;
}

bool OpenCommand::execute(std::vector<std::string> tokenized_cmd) {
    if (!validate(tokenized_cmd))
        return false;

    JsonManager* json_manager = getJsonManager();
    json_manager -> open(tokenized_cmd[1]);
    return true;
}

bool CloseCommand::validate(std::vector<std::string> tokenized_cmd) {
    if ((tokenized_cmd.size() == 1) && (tokenized_cmd[0] == getName()))
        return true;

    return false;
}

bool CloseCommand::execute(std::vector<std::string> tokenized_cmd) {
    if (!validate(tokenized_cmd)) 
        return false;

    JsonManager* json_manager = getJsonManager();
    json_manager -> close();
    return true;
}

bool ExitCommand::validate(std::vector<std::string> tokenized_cmd) {
    if ((tokenized_cmd.size() == 1) && (tokenized_cmd[0] == getName()))
        return true;

    return false;
}

bool ExitCommand::execute(std::vector<std::string> tokenized_cmd) {
    if (!validate(tokenized_cmd))
        return false;

    std::cout << "Exiting..." << std::endl;
    exit(0);
}

bool SaveCommand::validate(std::vector<std::string> tokenized_cmd) {
    if ((tokenized_cmd.size() == 1) && (tokenized_cmd[0] == getName()))
        return true;

    return false;
}

bool SaveCommand::execute(std::vector<std::string> tokenized_cmd) {
    if (!validate(tokenized_cmd))
        return false;

    JsonManager* json_manager = getJsonManager();
    json_manager -> save();
    return true;
}

bool SaveAsCommand::validate(std::vector<std::string> tokenized_cmd) {
    if ((tokenized_cmd.size() != 2) || (tokenized_cmd[0] != getName()))
        return false;

    return true;
}

bool SaveAsCommand::execute(std::vector<std::string> tokenized_cmd) {
    if (!validate(tokenized_cmd))
        return false;

    JsonManager* json_manager = getJsonManager();
    json_manager -> saveAs(tokenized_cmd[1]);
    return true;
}


bool SearchCommand::validate(std::vector<std::string> tokenized_cmd) {
    if ((tokenized_cmd.size() != 2) || (tokenized_cmd[0] != getName()))
        return false;

    return true;
}

bool SearchCommand::execute(std::vector<std::string> tokenized_cmd) {
    if (!validate(tokenized_cmd))
        return false;

    JsonManager* json_manager = getJsonManager();
    std::vector<std::string> result = json_manager -> search(tokenized_cmd[1]);
    
    std::string unformatted = "";
    for(std::string curr : result)
        unformatted += curr;

    std::cout << JsonWhitespaceFormatter::format(unformatted) << std::endl;

    return true;
}

bool ContainsCommand::validate(std::vector<std::string> tokenized_cmd) {
    if ((tokenized_cmd.size() != 2) || (tokenized_cmd[0] != getName()))
        return false;

    return true;
}

bool ContainsCommand::execute(std::vector<std::string> tokenized_cmd) {
    if (!validate(tokenized_cmd))
        return false;

    JsonManager* json_manager = getJsonManager();

    if (json_manager -> contains(tokenized_cmd[1]))
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;

    return true;
}

bool SetCommand::validate(std::vector<std::string> tokenized_cmd) {
    if ((tokenized_cmd.size() != 3) || (tokenized_cmd[0] != getName()))
        return false;

    return true;
}

bool SetCommand::execute(std::vector<std::string> tokenized_cmd) {
    if (!validate(tokenized_cmd))
        return false;

    JsonManager* json_manager = getJsonManager();
    json_manager ->set(tokenized_cmd[1], tokenized_cmd[2]);
    return true;
}

bool CreateCommand::validate(std::vector<std::string> tokenized_cmd) {
    if ((tokenized_cmd.size() != 3) || (tokenized_cmd[0] != getName()))
        return false;

    return true;
}

bool CreateCommand::execute(std::vector<std::string> tokenized_cmd) {
    if (!validate(tokenized_cmd))
        return false;

    JsonManager* json_manager = getJsonManager();
    json_manager ->create(tokenized_cmd[1], tokenized_cmd[2]);
    return true;
}

bool DeleteCommand::validate(std::vector<std::string> tokenized_cmd) {
    if ((tokenized_cmd.size() != 2) || (tokenized_cmd[0] != getName()))
        return false;

    return true;
}

bool DeleteCommand::execute(std::vector<std::string> tokenized_cmd) {
    if(!validate(tokenized_cmd))
        return false;

    JsonManager* json_manager = getJsonManager();
    json_manager -> delete_element(tokenized_cmd[1]);
    return true;
}

bool MoveCommand::validate(std::vector<std::string> tokenized_cmd) {
    if ((tokenized_cmd.size() != 3) || (tokenized_cmd[0] != getName()))
        return false;

    return true;
}

bool MoveCommand::execute(std::vector<std::string> tokenized_cmd) {
    if(!validate(tokenized_cmd))
        return false;

    JsonManager* json_manager = getJsonManager();
    json_manager -> move(tokenized_cmd[1], tokenized_cmd[2]);
    return true;
}