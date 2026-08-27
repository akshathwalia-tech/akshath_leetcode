#include <string>

class Solution {
public:
    int maximum69Number (int num) {
        std::string s = std::to_string(num);
        for (char &c : s) {
            if (c == '6') {
                c = '9';
                break;
            }
        }
        return std::stoi(s);
    }
};
// we convert this number into string and then change the first occurence of 6 to 9 and return the answer