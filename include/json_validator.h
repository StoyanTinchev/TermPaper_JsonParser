#ifndef JSON_VALIDATOR_H
#define JSON_VALIDATOR_H

#include <string>
#include <stack>
#include <cctype>

class JsonValidator {
public:
    static bool validate(const std::string &json) {
        std::stack<char> brackets;
        bool in_quotes = false;
        bool escaped = false;
        for (char c : json) {
            if (c == '\\') {
                escaped = !escaped;
                continue;
            }
            if (c == '"' && !escaped) {
                in_quotes = !in_quotes;
            } else if (!in_quotes) {
                switch (c) {
                    case '{':
                    case '[':
                        brackets.push(c);
                        break;
                    case '}':
                        if (brackets.empty() || brackets.top() != '{') {
                            return false;
                        }
                        brackets.pop();
                        break;
                    case ']':
                        if (brackets.empty() || brackets.top() != '[') {
                            return false;
                        }
                        brackets.pop();
                        break;
                }
            }
            if (escaped) {
                escaped = false;
            }
        }
        return brackets.empty() && !in_quotes;
    }
};

#endif // JSON_VALIDATOR_H
