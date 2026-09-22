#include <vector>

using namespace std;

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        vector<bool> exists(201, false);
        for (int x : nums) {
            exists[x] = true;
        }

        int count = 0;
        for (int x : nums) {
            if (x - diff >= 0 && x + diff <= 200) {
                if (exists[x - diff] && exists[x + diff]) {
                    count++;
                }
            }
        }

        return count;
    }
};