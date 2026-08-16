class Solution {
public:
    // Function to return the length of the longest substring that can be made of repeating characters
    // by replacing at most k characters
    int characterReplacement(string s, int k) {
        
        // Map to count frequency of characters in current window
        unordered_map<char, int> freq;

        // Left pointer of the sliding window
        int left = 0;

        // Tracks the count of the most frequent character in the window
        int max_freq = 0;

        // Stores the result (maximum length found)
        int max_len = 0;

        // Traverse the string with right pointer
        for (int right = 0; right < s.length(); right++) {

            // Increase frequency of the current character
            freq[s[right]]++;

            // Update max frequency seen so far in the window
            max_freq = max(max_freq, freq[s[right]]);

            // If window is invalid (needs more than k replacements)
            while ((right - left + 1) - max_freq > k) {

                // Decrease frequency of the character at left
                freq[s[left]]--;

                // Shrink the window from the left
                left++;
            }

            // Update max_len with current valid window size
            max_len = max(max_len, right - left + 1);
        }

        // Return the final result
        return max_len;
    }
};
