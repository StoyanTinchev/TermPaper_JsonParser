add_executable(validator_test json_validation_test.cpp)
add_test(NAME "Json Validator Test - Validate a correct JSON format." COMMAND validator_test ${CMAKE_SOURCE_DIR}/test/test-json.txt "VALID")
add_test(NAME "Json Validator Test - Throw an error for incorrect JSON format." COMMAND validator_test ${CMAKE_SOURCE_DIR}/test/invalid-test-json.txt "INVALID")