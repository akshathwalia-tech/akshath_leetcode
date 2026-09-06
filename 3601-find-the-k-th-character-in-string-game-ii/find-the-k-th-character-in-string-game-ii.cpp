#include <vector>

using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long idx = k - 1; // Convert to 0-based index
        int totalShifts = 0;

        for (int i = 0; i < operations.size() && (1LL << i) <= idx; ++i) {
            // Check if the i-th bit is set
            if ((idx >> i) & 1LL) {
                if (operations[i] == 1) {
                    totalShifts++;
                }
            }
        }

        return 'a' + (totalShifts % 26);
    }
};