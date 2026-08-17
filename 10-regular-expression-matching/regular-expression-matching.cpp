#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int m = s.length();
        int n = p.length();

        // dp[i][j] will be true if s[0...i-1] matches p[0...j-1]
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

        // Base case: empty string matches empty pattern
        dp[0][0] = true;

        // Base cases for patterns like a*, a*b*, a*b*c* matching an empty string
        for (int j = 2; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    // Current characters match
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // Case 1: '*' counts as 0 occurrences of the preceding element
                    dp[i][j] = dp[i][j - 2];

                    // Case 2: '*' counts as 1 or more occurrences
                    // Valid only if preceding element in pattern matches current char in s
                    char prevChar = p[j - 2];
                    if (prevChar == '.' || prevChar == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[m][n];
    }
};