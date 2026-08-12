#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t found = haystack.find(needle);
        
        // string::npos is returned if the substring is not found
        if (found != string::npos) {
            return static_cast<int>(found);
        }
        
        return -1;
    }
};