#include <cmd_interpreter/cmd_interpreter.h>
#include <sstream>

CMDInterpreter::CMDInterpreter(JsonManager *json_manager) {
    Command* supp_commands[] = {
        new ValidateCommand(json_manager),
        new PrintCommand(json_manager),
        new OpenCommand(json_manager),
        new CloseCommand(json_manager),
        new SaveCommand(json_manager),
        new SaveAsCommand(json_manager),
        new ExitCommand(json_manager),
        new SearchCommand(json_manager),
        new ContainsCommand(json_manager),
        new SetCommand(json_manager),
        new CreateCommand(json_manager),
        new DeleteCommand(json_manager),
        new MoveCommand(json_manager)
    };

    int size = sizeof(supp_commands) / sizeof(supp_commands[0]);

    for (int i = 0; i < size; i ++)
        supported_commands.push_back(supp_commands[i]);
}

CMDInterpreter::~CMDInterpreter() {
    int idx = 0;
    while(!supported_commands.empty()) {
        Command *cmd = supported_commands[idx];
        delete cmd;
    }
}

std::vector<std::string> CMDInterpreter::tokenizeCommand(std::string& input_cmd) {
    std::vector<std::string> tokenized_command;
    std::istringstream iss(input_cmd);

    std::string curr_token;
    while(iss >> curr_token) {
        tokenized_command.push_back(curr_token);
    }

    return tokenized_command;
}

bool CMDInterpreter::interpret(std::string& cmd) {
    std::vector<std::string> tokenized_command = tokenizeCommand(cmd);

    Command* fetched_cmd = getCommandByName(tokenized_command[0]);

    if (fetched_cmd == nullptr)
        throw CommandNotSupportedException(tokenized_command[0] + " is not a supported command!");
    
    return fetched_cmd -> execute(tokenized_command);
}

Command* CMDInterpreter::getCommandByName(std::string name) {
    for (Command* cmd : supported_commands)
        if (cmd -> getName() == name)
            return cmd;

    return nullptr;
}