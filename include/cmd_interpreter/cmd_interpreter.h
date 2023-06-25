/**
 * @file cmd_interpreter.h
 * @brief Definition of the class of the Command Interpreter.
 */

#ifndef CMD_INTERPRETER_H
#define CMD_INTERPRETER_H

#include "command.h"
#include <json_manager.h>
#include <stdexcept>

/**
 * @class CMDInterpreter
 * @brief Class for the Command Interpreter.
 *
 * It serves as a translator of string-based commands to command classes and then executing it.
 */
class CMDInterpreter {
    private: 
        std::vector<Command*> supported_commands; /**< A list/vector of supported commands. */
        /**
         * @brief Fetches a command by its name.
         *
         * @param name The name of the command.
         * @return A pointer to the command with the corresponding name.
         */
        Command* getCommandByName(std::string name); 
        /**
         * @brief Splits a command string into a list of strings.
         *
         * @param input_cmd The command string to split.
         * @return A vector of strings/tokens.
         */
        std::vector<std::string> tokenizeCommand(std::string& input_cmd);

    public:
        /**
         * @brief Constructor for CMDInterpreter class.
         *
         * @param jsonManager A pointer to an instance of JsonManager class.
         */
        CMDInterpreter(JsonManager* jsonManager); 
        /**
         * @brief Destructor for CMDInterpreter class.
         */
        ~CMDInterpreter();
        /**
         * @brief Interprets a command string.
         *
         * @param cmd The input string commmand.
         * @return True if the command executed successfully, false otherwise. Can throw a runtime error.
         */
        bool interpret(std::string& cmd);
};


/**
 * @brief Exception thrown when a non-supported command was passed.
 */
class CommandNotSupportedException : public std::runtime_error {
    public:
        /**
         * @brief Constructor for the CommandNotSupportedException 
         *
         * @param msg The string error message.
         */
        explicit CommandNotSupportedException(const std::string &msg) 
            : std::runtime_error("CommandNotSupportedException: " + msg) {}
};


#endif // CMD_INTERPRETER_H