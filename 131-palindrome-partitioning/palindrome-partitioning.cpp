#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool ispalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void backtrack(int start, int n, vector<vector<string>>& result, vector<string>& current, const string& s) {
        if (start == n) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < n; i++) {
            if (ispalindrome(s, start, i)) {
            
                current.push_back(s.substr(start, i - start + 1));
                
                backtrack(i + 1, n, result, current, s);
                
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> result;
        vector<string> current;
        backtrack(0, n, result, current, s);
        return result;
    }
};