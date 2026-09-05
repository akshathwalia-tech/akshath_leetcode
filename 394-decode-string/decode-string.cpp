#include <string>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString = "";
        int currentNum = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                currentNum = currentNum * 10 + (ch - '0');
            } else if (ch == '[') {
                // Push the context before this bracket
                countStack.push(currentNum);
                stringStack.push(currentString);
                // Reset for the new scope
                currentString = "";
                currentNum = 0;
            } else if (ch == ']') {
                // Pop the count and previous string
                int repeatCount = countStack.top();
                countStack.pop();
                string prevString = stringStack.top();
                stringStack.pop();

                // Build repeated string
                string repeated = "";
                while (repeatCount--) {
                    repeated += currentString;
                }
                currentString = prevString + repeated;
            } else {
                currentString += ch;
            }
        }

        return currentString;
    }
};