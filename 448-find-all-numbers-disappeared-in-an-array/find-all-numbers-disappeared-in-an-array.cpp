#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        // Step 1: Mark visited indices by negating the value at that index
        for (int i = 0; i < nums.size(); i++) {
            int targetIndex = std::abs(nums[i]) - 1;
            
            if (nums[targetIndex] > 0) {
                nums[targetIndex] = -nums[targetIndex];
            }
        }
        
        // Step 2: Indices with positive numbers were never visited
        std::vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        
        return result;
    }
};