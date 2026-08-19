#include <string>
#include <vector>
#include <climits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) return "";

        // Frequency map for characters in t (using ASCII array for speed)
        std::vector<int> targetFreq(128, 0);
        for (char ch : t) {
            targetFreq[ch]++;
        }

        int left = 0;
        int minLen = INT_MAX;
        int startIndex = 0;
        int matchedCount = 0; // Number of required characters matched

        for (int right = 0; right < s.length(); right++) {
            char rightChar = s[right];

            // If the character is needed, increment matchedCount
            if (targetFreq[rightChar] > 0) {
                matchedCount++;
            }
            // Decrement frequency in map (negative means excess in window)
            targetFreq[rightChar]--;

            // When window contains all characters of t, shrink from left
            while (matchedCount == t.length()) {
                int currentLen = right - left + 1;
                if (currentLen < minLen) {
                    minLen = currentLen;
                    startIndex = left;
                }

                char leftChar = s[left];
                targetFreq[leftChar]++;

                // If removing leftChar breaks the required count, reduce matchedCount
                if (targetFreq[leftChar] > 0) {
                    matchedCount--;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};