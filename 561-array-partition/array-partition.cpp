#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // Step 1: Sort the array in non-decreasing order
        sort(nums.begin(), nums.end());

        int sum = 0;
        // Step 2: Sum elements at even indices (0, 2, 4, ...)
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }

        return sum;
    }
};