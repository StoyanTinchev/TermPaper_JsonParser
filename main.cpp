#include <iostream>
#include <cmd_interpreter/cmd_interpreter.h>

int main() {
   JsonManager json_manager;
   CMDInterpreter interpreter(&json_manager);

   while (1) {
       std::string cmd;
       std::getline(std::cin, cmd);
       try{
            if (!interpreter.interpret(cmd))
                std::cerr << "Error occured during execution of the command." << std::endl;
       }
       catch(std::runtime_error exception) {
            std::cerr << exception.what() << std::endl;
       }
   }
}
