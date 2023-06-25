/**
 * @file command.h
 * @brief Defines Command abstract class and classes for all supported commands.
 */

#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <json_manager.h>

/**
 * @class Command
 * @brief The abstract class Command.
 *
 * An abstract class that is inherited by all supported commands' classes.
 */
class Command {
    private:
        std::string name; /**< The name of the command. */
        JsonManager* json_man; /**< A pointer to a JsonManager instance. */
        /**
         * @brief Pure virtual function that validates a string-based tokenized command.
         * @param tokenized_cmd A vector of the split tokens of the string-based command.
         * @returns True if the command syntax is valid, false otherwise.
        */
        virtual bool validate(std::vector<std::string> tokenized_cmd) = 0;
    
    public: 
        /**
         * @brief Constructor for Command class used for initialization.
         * @param name The name of the command.
         * @param json_manager A pointer to a JsonManager instance.
        */
        Command(std::string name, JsonManager* json_manager) {
            this->name = name;
            this->json_man = json_manager;
        }
        /**
         * @brief Getter for the 'name' field.
         * @returns The name of the command.
        */
        std::string getName() {return name;} 
        /**
         * @brief Getter for the 'json_man' field.
         * @returns A pointer to a JsonManager instance.
        */
        JsonManager* getJsonManager() {return json_man;}
        /**
         * @brief Pure virtual function that executes a string-based tokenized command.
         * @param tokenized_cmd A vector of the tokens of a split string command.
        */
        virtual bool execute(std::vector<std::string> tokenized_cmd) = 0;
};

/**
 * @class ValidateCommand
 * @brief A class representing the "validate" command.
*/
class ValidateCommand : public Command {
    private: 
        /**
         * @brief Validates the syntax of the string command "validate".
         * @param tokenized_cmd The tokenized string command.
         * @return True if the command syntax is correct, false otherwise.
        */
        bool validate(std::vector<std::string> tokenized_cmd) override;

    public:
        /**
         * @brief Contructor of the class.
         * @param jsonManager A pointer to a JsonManager instance.
        */
        explicit ValidateCommand(JsonManager* jsonManager) : Command("validate", jsonManager) {}
        /**
         * @brief Executes the "validate" command.
         * @param tokenized_cmd The tokenized string command.
         * @return True if the command executed without problems, false otherwise.
        */
        bool execute(std::vector<std::string> tokenized_cmd) override;
};

/**
 * @class PrintCommand
 * @brief A class representing the "print" command.
*/
class PrintCommand : public Command {
    private:
        /**
         * @brief Validates the syntax of the string command "print".
         * @param tokenized_cmd The tokenized string command.
         * @return True if the command syntax is correct, false otherwise.
        */
        bool validate(std::vector<std::string> tokenized_cmd) override;

    public:
        /**
         * @brief Contructor of the class.
         * @param jsonManager A pointer to a JsonManager instance.
        */
        explicit PrintCommand(JsonManager* jsonManager) : Command("print", jsonManager) {}
        /**
         * @brief Executes the "print" command.
         * @param tokenized_cmd The tokenized string command.
         * @return True if the command executed without problems, false otherwise.
        */
        bool execute(std::vector<std::string> tokenized_cmd) override;
};

/**
 * @class OpenCommand
 * @brief A class representing the "open" command.
*/
class OpenCommand : public Command {
    private:
        /**
         * @brief Validates the syntax of the string command "open".
         * @param tokenized_cmd The tokenized string command.
         * @return True if the command syntax is correct, false otherwise.
        */
        bool validate(std::vector<std::string> tokenized_cmd) override;

    public:
        /**
         * @brief Contructor of the class.
         * @param jsonManager A pointer to a JsonManager instance.
        */
        explicit OpenCommand(JsonManager* jsonManager) : Command("open", jsonManager) {}
        /**
         * @brief Executes the "open" command.
         * @param tokenized_cmd The tokenized string command.
         * @return True if the command executed without problems, false otherwise.
        */
        bool execute(std::vector<std::string> tokenized_cmd) override;
};

/**
 * @class CloseCommand
 * @brief A class representing the "close" command.
*/
class CloseCommand : public Command {
    private:
        /**
         * @brief Validates the syntax of the string command "close".
         * @param tokenized_cmd The tokenized string command.
         * @return True if the command syntax is correct, false otherwise.
        */
        bool validate(std::vector<std::string> tokenized_cmd) override;

    public:
        /**
         * @brief Contructor of the class.
         * @param jsonManager A pointer to a JsonManager instance.
        */
        explicit CloseCommand(JsonManager* jsonManager) : Command("close", jsonManager) {}
        /**
         * @brief Executes the "close" command.
         * @param tokenized_cmd The tokenized string command.
         * @return True if the command executed without problems, false otherwise.
        */
        bool execute(std::vector<std::string> tokenized_cmd) override;
};

/**
 * @class ExitCommand
 * @brief A class representing the "exit" command.
*/
class ExitCommand : public Command {
private:
    /**
     * @brief Validates the syntax of the string command "exit".
     * @param tokenized_cmd The tokenized string command.
     * @return True if the command syntax is correct, false otherwise.
    */
    bool validate(std::vector<std::string> tokenized_cmd) override;

public:
    /**
     * @brief Contructor of the class.
     * @param jsonManager A pointer to a JsonManager instance.
    */
    explicit ExitCommand(JsonManager* jsonManager) : Command("exit", jsonManager) {}
    /**
     * @brief Executes the "exit" command.
     * @param tokenized_cmd The tokenized string command.
     * @return True if the command executed without problems, false otherwise.
    */
    bool execute(std::vector<std::string> tokenized_cmd) override;
};

/**
 * @class SaveCommand
 * @brief A class representing the "save" command.
*/
class SaveCommand : public Command {
private:
    /**
     * @brief Validates the syntax of the string command "save".
     * @param tokenized_cmd The tokenized string command.
     * @return True if the command syntax is correct, false otherwise.
    */
    bool validate(std::vector<std::string> tokenized_cmd) override;

public:
    /**
     * @brief Contructor of the class.
     * @param jsonManager A pointer to a JsonManager instance.
    */
    explicit SaveCommand(JsonManager* jsonManager) : Command("save", jsonManager) {}
    /**
     * @brief Executes the "save" command.
     * @param tokenized_cmd The tokenized string command.
     * @return True if the command executed without problems, false otherwise.
    */
    bool execute(std::vector<std::string> tokenized_cmd) override;
};

/**
 * @class SaveAsCommand
 * @brief A class representing the "save as" command.
*/
class SaveAsCommand : public Command {
private:
    /**
     * @brief Validates the syntax of the string command "save as".
     * @param tokenized_cmd The tokenized string command.
     * @return True if the command syntax is correct, false otherwise.
    */
    bool validate(std::vector<std::string> tokenized_cmd) override;

public:
    /**
     * @brief Contructor of the class.
     * @param jsonManager A pointer to a JsonManager instance.
    */
    explicit SaveAsCommand(JsonManager* jsonManager) : Command("saveas", jsonManager) {}
    /**
     * @brief Executes the "save as" command.
     * @param tokenized_cmd The tokenized string command.
     * @return True if the command executed without problems, false otherwise.
    */
    bool execute(std::vector<std::string> tokenized_cmd) override;
};

/**
 * @class SearchCommand
 * @brief A class representing the "search" command.
*/
class SearchCommand : public Command {
private:
    /**
     * @brief Validates the syntax of the string command "search".
     * @param tokenized_cmd The tokenized string command.
     * @return True if the command syntax is correct, false otherwise.
    */
    bool validate(std::vector<std::string> tokenized_cmd) override;

public:
    /**
     * @brief Contructor of the class.
     * @param jsonManager A pointer to a JsonManager instance.
    */
    explicit SearchCommand(JsonManager* jsonManager) : Command("search", jsonManager) {}
    /**
     * @brief Executes the "search" command.
     * @param tokenized_cmd The tokenized string command.
     * @return True if the command executed without problems, false otherwise.
    */
    bool execute(std::vector<std::string> tokenized_cmd) override;
};

/**
 * @class ContainsCommand
 * @brief A class representing the "contains" command.
*/
class ContainsCommand : public Command {
private:
    /**
     * @brief Validates the syntax of the string command "contains".
     * @param tokenized_cmd The tokenized string command.
     * @return True if the command syntax is correct, false otherwise.
    */
    bool validate(std::vector<std::string> tokenized_cmd) override;

public:
    /**
     * @brief Contructor of the class.
     * @param jsonManager A pointer to a JsonManager instance.
    */
    explicit ContainsCommand(JsonManager* jsonManager) : Command("contains", jsonManager) {}
    /**
     * @brief Executes the "contains" command.
     * @param tokenized_cmd The tokenized string command.
     * @return True if the command executed without problems, false otherwise.
    */
    bool execute(std::vector<std::string> tokenized_cmd) override;
};

/**
 * @class SetCommand
 * @brief A class representing the "set" command.
*/
class SetCommand : public Command {
private:
    /**
     * @brief Validates the syntax of the string command "set".
     * @param tokenized_cmd The tokenized string command.
     * @return True if the command syntax is correct, false otherwise.
    */
    bool validate(std::vector<std::string> tokenized_cmd) override;

public:
    /**
     * @brief Contructor of the class.
     * @param jsonManager A pointer to a JsonManager instance.
    */
    explicit SetCommand(JsonManager* jsonManager) : Command("set", jsonManager) {}
    /**
     * @brief Executes the "set" command.
     * @param tokenized_cmd The tokenized string command.
     * @return True if the command executed without problems, false otherwise.
    */
    bool execute(std::vector<std::string> tokenized_cmd) override;
};

/**
 * @class CreateCommand
 * @brief A class representing the "create" command.
*/
class CreateCommand : public Command {
private:
    /**
     * @brief Validates the syntax of the string command "create".
     * @param tokenized_cmd The tokenized string command.
     * @return True if the command syntax is correct, false otherwise.
    */
    bool validate(std::vector<std::string> tokenized_cmd) override;

public:
    /**
     * @brief Contructor of the class.
     * @param jsonManager A pointer to a JsonManager instance.
    */
    explicit CreateCommand(JsonManager* jsonManager) : Command("create", jsonManager) {}
    /**
     * @brief Executes the "create" command.
     * @param tokenized_cmd The tokenized string command.
     * @return True if the command executed without problems, false otherwise.
    */
    bool execute(std::vector<std::string> tokenized_cmd) override;
};

/**
 * @class DeleteCommand
 * @brief A class representing the "delete" command.
*/
class DeleteCommand : public Command {
private:
    /**
     * @brief Validates the syntax of the string command "delete".
     * @param tokenized_cmd The tokenized string command.
     * @return True if the command syntax is correct, false otherwise.
    */
    bool validate(std::vector<std::string> tokenized_cmd) override;

public:
    /**
     * @brief Contructor of the class.
     * @param jsonManager A pointer to a JsonManager instance.
    */
    explicit DeleteCommand(JsonManager* jsonManager) : Command("delete", jsonManager) {}
    /**
     * @brief Executes the "delete" command.
     * @param tokenized_cmd The tokenized string command.
     * @return True if the command executed without problems, false otherwise.
    */
    bool execute(std::vector<std::string> tokenized_cmd) override;
};

/**
 * @class MoveCommand
 * @brief A class representing the "move" command.
*/
class MoveCommand : public Command {
private:
    /**
     * @brief Validates the syntax of the string command "move".
     * @param tokenized_cmd The tokenized string command.
     * @return True if the command syntax is correct, false otherwise.
    */
    bool validate(std::vector<std::string> tokenized_cmd) override;

public:
    /**
     * @brief Contructor of the class.
     * @param jsonManager A pointer to a JsonManager instance.
    */
    explicit MoveCommand(JsonManager* jsonManager) : Command("move", jsonManager) {}
    /**
     * @brief Executes the "move" command.
     * @param tokenized_cmd The tokenized string command.
     * @return True if the command executed without problems, false otherwise.
    */
    bool execute(std::vector<std::string> tokenized_cmd) override;
};

#endif // COMMAND_H