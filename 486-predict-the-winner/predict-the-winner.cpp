#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int memo[21][21];

    int maxDiff(vector<int>& nums, int i, int j) {
        if (i == j) {
            return nums[i];
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int pickLeft = nums[i] - maxDiff(nums, i + 1, j);
        int pickRight = nums[j] - maxDiff(nums, i, j - 1);

        return memo[i][j] = max(pickLeft, pickRight);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        // Any array with even length is an automatic win for Player 1
        // because Player 1 can choose to take all even-indexed or all odd-indexed elements
        if (n % 2 == 0) return true;

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                memo[r][c] = -1;
            }
        }

        return maxDiff(nums, 0, n - 1) >= 0;
    }
};