#include <string>
#include <vector>

class Solution {
public:
    std::string decodeMessage(std::string key, std::string message) {
        std::vector<char> mapping(26, 0);
        char current_char = 'a';

        // Build substitution table based on the first occurrence of each letter
        for (char ch : key) {
            if (ch != ' ' && mapping[ch - 'a'] == 0) {
                mapping[ch - 'a'] = current_char;
                current_char++;
            }
        }

        // Decode the message
        std::string decoded = message;
        for (int i = 0; i < decoded.size(); ++i) {
            if (decoded[i] != ' ') {
                decoded[i] = mapping[decoded[i] - 'a'];
            }
        }

        return decoded;
    }
};