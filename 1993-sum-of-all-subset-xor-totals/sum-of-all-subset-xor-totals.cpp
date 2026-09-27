class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int bitwiseOr = 0;
        
        // Calculate the bitwise OR of all elements in the array
        for (int num : nums) {
            bitwiseOr |= num;
        }
        
        // The total sum is bitwiseOr multiplied by 2^(n - 1)
        return bitwiseOr << (nums.size() - 1);
    }
};