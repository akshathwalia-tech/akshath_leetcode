#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        // 1. Traverse each digit in the string
        for (char c : num) {
            // While stack is not empty, k > 0, and top of stack > current digit
            while (!st.empty() && k > 0 && st.top() > c) {
                st.pop(); // Remove the peak digit
                k--;
            }
            st.push(c);
        }

        // 2. If k > 0 remains, pop the remaining digits from the right end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // 3. Extract elements from the stack into a string
        // (Note: Stack pops elements in REVERSE order)
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // Reverse to get the correct left-to-right order
        reverse(ans.begin(), ans.end());

        // 4. Remove leading zeros
        int start = 0;
        while (start < ans.size() && ans[start] == '0') {
            start++;
        }

        ans = ans.substr(start);

        // 5. If string becomes empty after removing leading zeros, return "0"
        return ans.empty() ? "0" : ans;
    }
};