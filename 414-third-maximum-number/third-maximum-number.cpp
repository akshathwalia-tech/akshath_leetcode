#include <vector>
#include <climits>

class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        for (int num : nums) {
            // Skip duplicates of already tracked maximums
            if (num == first || num == second || num == third) {
                continue;
            }

            // Shift values down when a new maximum is found
            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second) {
                third = second;
                second = num;
            } else if (num > third) {
                third = num;
            }
        }

        // If third distinct maximum was never assigned, return the first (maximum)
        return (third == LLONG_MIN) ? (int)first : (int)third;
    }
};