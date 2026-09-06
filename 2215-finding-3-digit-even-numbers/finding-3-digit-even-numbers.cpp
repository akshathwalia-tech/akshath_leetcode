#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> count(10, 0);
        for (int d : digits) {
            count[d]++;
        }

        vector<int> result;

        // Check every 3-digit even number
        for (int num = 100; num <= 998; num += 2) {
            int hundreds = num / 100;
            int tens = (num / 10) % 10;
            int units = num % 10;

            // Temporarily use the digits
            count[hundreds]--;
            count[tens]--;
            count[units]--;

            // If all counts remain non-negative, the number can be formed
            if (count[hundreds] >= 0 && count[tens] >= 0 && count[units] >= 0) {
                result.push_back(num);
            }

            // Backtrack/restore frequencies
            count[hundreds]++;
            count[tens]++;
            count[units]++;
        }

        return result;
    }
};