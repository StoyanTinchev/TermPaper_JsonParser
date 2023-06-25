add_executable(json_manager_test json_manager_test.cpp
                ${CMAKE_SOURCE_DIR}/include/json_base/json_element.h
                ${CMAKE_SOURCE_DIR}/include/json_base/json_key.h
                ${CMAKE_SOURCE_DIR}/include/json_base/json_value.h 
                ${CMAKE_SOURCE_DIR}/src/json_base/json_value.cpp
                ${CMAKE_SOURCE_DIR}/include/json_base/json_object.h 
                ${CMAKE_SOURCE_DIR}/src/json_base/json_object.cpp
                ${CMAKE_SOURCE_DIR}/include/json_base/json_array.h 
                ${CMAKE_SOURCE_DIR}/src/json_base/json_array.cpp
                ${CMAKE_SOURCE_DIR}/include/json_validator.h
                ${CMAKE_SOURCE_DIR}/include/json_parser.h 
                ${CMAKE_SOURCE_DIR}/src/json_parser.cpp
                ${CMAKE_SOURCE_DIR}/include/json_exceptions.h
                ${CMAKE_SOURCE_DIR}/include/json_manager.h 
                ${CMAKE_SOURCE_DIR}/src/json_manager.cpp
                ${CMAKE_SOURCE_DIR}/include/json_whitespace_formatter.h 
                ${CMAKE_SOURCE_DIR}/src/json_whitespace_formatter.cpp)

add_test(NAME "Json Manager Validation Test - No invalid JSON syntax." 
            COMMAND json_manager_test ${CMAKE_SOURCE_DIR}/test/test-json.json "VALIDATE")
        
add_test(NAME "Json Manager Validation Test - Invalid JSON syntax."
            COMMAND json_manager_test ${CMAKE_SOURCE_DIR}/test/invalid-test-json.json "VALIDATE")

set_tests_properties("Json Manager Validation Test - Invalid JSON syntax." PROPERTIES WILL_FAIL true)

add_test(NAME "Json Manager Search Test."
            COMMAND json_manager_test ${CMAKE_SOURCE_DIR}/test/test-json.json "SEARCH")

add_test(NAME "Json Manager Contains Test." 
            COMMAND json_manager_test ${CMAKE_SOURCE_DIR}/test/test-json.json "CONTAINS")

add_test(NAME "Json Manager Set Test." 
            COMMAND json_manager_test ${CMAKE_SOURCE_DIR}/test/test-json.json "SET")

add_test(NAME "Json Manager Create Test."
            COMMAND json_manager_test ${CMAKE_SOURCE_DIR}/test/test-json.json "CREATE")

add_test(NAME "Json Manager Delete Test." 
            COMMAND json_manager_test ${CMAKE_SOURCE_DIR}/test/test-json.json "DELETE")

add_test(NAME "Json Manager Move Test."
            COMMAND json_manager_test ${CMAKE_SOURCE_DIR}/test/test-json.json "MOVE")
