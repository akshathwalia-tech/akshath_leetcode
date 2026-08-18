#include <vector>
#include <utility>

class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            if (nums[left] % 2 > nums[right] % 2) {
                // left is odd (1) and right is even (0) -> swap them
                std::swap(nums[left], nums[right]);
            }
            if (nums[left] % 2 == 0) {
                left++;
            }
            if (nums[right] % 2 == 1) {
                right--;
            }
        }

        return nums;
    }
};