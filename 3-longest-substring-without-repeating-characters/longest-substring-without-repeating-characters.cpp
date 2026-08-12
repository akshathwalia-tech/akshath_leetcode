#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Map to store the last seen index of each character
        vector<int> lastSeen(256, -1);
        
        int maxLength = 0;
        int left = 0; // Left boundary of sliding window
        
        for (int right = 0; right < s.length(); right++) {
            char currentChar = s[right];
            
            // If character was seen before AND is inside current window
            if (lastSeen[currentChar] >= left) {
                // Move left pointer right past the duplicate character
                left = lastSeen[currentChar] + 1;
            }
            
            // Update last seen position of current character
            lastSeen[currentChar] = right;
            
            // Calculate maximum length of current valid window
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};