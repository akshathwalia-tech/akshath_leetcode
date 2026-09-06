#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int fact = 1;

        // Populate available digits and compute (n - 1)!
        for (int i = 1; i < n; i++) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        // Convert k to 0-indexed
        k = k - 1;
        string result = "";

        while (true) {
            // Determine which digit goes next
            int index = k / fact;
            result += to_string(numbers[index]);

            // Remove the used digit
            numbers.erase(numbers.begin() + index);

            if (numbers.empty()) {
                break;
            }

            // Update k and fact for the next position
            k = k % fact;
            fact = fact / numbers.size();
        }

        return result;
    }
};