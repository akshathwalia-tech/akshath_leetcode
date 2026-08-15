#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits; // No carry left, return directly
            }
            digits[i] = 0; // Carry propagates to the left
        }
        
        // All digits were 9 (e.g., 999 -> 1000)
        vector<int> result(n + 1, 0);
        result[0] = 1;
        return result;
    }
};