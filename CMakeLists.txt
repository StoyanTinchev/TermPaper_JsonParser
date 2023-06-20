cmake_minimum_required(VERSION 3.25)
project(TermPaper_JsonParser)

set(CMAKE_CXX_STANDARD 11)

add_executable(TermPaper_JsonParser
        main.cpp
        include/json_base/json_element.h
        include/json_base/json_key.h
        include/json_base/json_value.h src/json_base/json_value.cpp
        include/json_base/json_object.h src/json_base/json_object.cpp
        include/json_base/json_array.h src/json_base/json_array.cpp
        include/json_validator.h
        include/json_parser.h src/json_parser.cpp)
