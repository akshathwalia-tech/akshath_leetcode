#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<string, vector<int>> memo;

public:
    vector<int> diffWaysToCompute(string expression) {
        // Return cached results if this subexpression has been evaluated
        if (memo.count(expression)) {
            return memo[expression];
        }

        vector<int> results;

        for (int i = 0; i < expression.length(); i++) {
            char ch = expression[i];

            // If the character is an operator, split the expression
            if (ch == '+' || ch == '-' || ch == '*') {
                string leftExpr = expression.substr(0, i);
                string rightExpr = expression.substr(i + 1);

                vector<int> leftResults = diffWaysToCompute(leftExpr);
                vector<int> rightResults = diffWaysToCompute(rightExpr);

                // Combine every outcome from the left with every outcome from the right
                for (int leftVal : leftResults) {
                    for (int rightVal : rightResults) {
                        if (ch == '+') {
                            results.push_back(leftVal + rightVal);
                        } else if (ch == '-') {
                            results.push_back(leftVal - rightVal);
                        } else if (ch == '*') {
                            results.push_back(leftVal * rightVal);
                        }
                    }
                }
            }
        }

        // Base case: expression contains only digits (no operators found)
        if (results.empty()) {
            results.push_back(stoi(expression));
        }

        return memo[expression] = results;
    }
};