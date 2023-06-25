#include <json_whitespace_formatter.h>

std::string JsonWhitespaceFormatter::format(const std::string &unformatted_output) {
    std::string formatted_output = "";

    int idx = 0;
    int tab_level = 0;
    while(idx < unformatted_output.size()) {
        switch (unformatted_output[idx]) {
            case '{':
            case '[':
                formatted_output += unformatted_output[idx];
                tab_level ++;
                formatted_output += '\n';

                for (int i = 0; i < tab_level; i ++)
                    formatted_output += '\t';
                
                break;

            case ',':
                formatted_output += unformatted_output[idx++];
                formatted_output += unformatted_output[idx];
                formatted_output += '\n';

                for (int i = 0; i < tab_level; i ++)
                    formatted_output += '\t';

                break;

            case '}':
            case ']':
                formatted_output += '\n';
                tab_level --;

                for (int i = 0; i < tab_level; i ++)
                    formatted_output += '\t';

                formatted_output += unformatted_output[idx];
                break;

            default:
                formatted_output += unformatted_output[idx];
        }
        idx ++;
    }

    return formatted_output;
}
