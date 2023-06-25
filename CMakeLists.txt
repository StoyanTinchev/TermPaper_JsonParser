cmake_minimum_required(VERSION 3.25)
project(TermPaper_JsonParser)

set(CMAKE_CXX_STANDARD 17)
include(CTest)
enable_testing()
add_compile_options(-g)
include_directories(include)

add_subdirectory(test/)

add_executable(TermPaper_JsonParser
        main.cpp
        include/json_base/json_element.h
        include/json_base/json_key.h
        include/json_base/json_value.h src/json_base/json_value.cpp
        include/json_base/json_object.h src/json_base/json_object.cpp
        include/json_base/json_array.h src/json_base/json_array.cpp
        include/json_validator.h
        include/json_parser.h src/json_parser.cpp
        include/json_exceptions.h
        include/json_manager.h src/json_manager.cpp
        include/cmd_interpreter/cmd_interpreter.h include/cmd_interpreter/command.h
        src/cmd_interpreter/cmd_interpreter.cpp src/cmd_interpreter/commands.cpp
        include/json_whitespace_formatter.h src/json_whitespace_formatter.cpp)

