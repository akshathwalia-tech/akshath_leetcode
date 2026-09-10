#include <vector>
#include <cstdint>

class Solution {
private:
    bool canPartition(int index, __int128 currentProduct, int pickedCount, 
                      const std::vector<int>& nums, long long target) {
        // Base case: processed all elements
        if (index == nums.size()) {
            // Must equal target and subset must be non-empty and proper
            return (currentProduct == target) && (pickedCount > 0) && (pickedCount < nums.size());
        }

        // Option 1: Include nums[index] in the subset (with pruning)
        if (target % nums[index] == 0 && currentProduct * nums[index] <= target) {
            if (canPartition(index + 1, currentProduct * nums[index], pickedCount + 1, nums, target)) {
                return true;
            }
        }

        // Option 2: Exclude nums[index] from the subset
        if (canPartition(index + 1, currentProduct, pickedCount, nums, target)) {
            return true;
        }

        return false;
    }

public:
    bool checkEqualPartitions(std::vector<int>& nums, long long target) {
        __int128 totalProduct = 1;
        __int128 targetSq = (__int128)target * target;

        for (int x : nums) {
            totalProduct *= x;
        }

        // Both subsets must multiply to target, so total product must be target^2
        if (totalProduct != targetSq) {
            return false;
        }

        return canPartition(0, 1, 0, nums, target);
    }
};