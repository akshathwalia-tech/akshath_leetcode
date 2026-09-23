#include <iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        // Create a bitmask of all 1s matching the bit-length of num
        unsigned int mask = 1;
        
        while (mask < static_cast<unsigned int>(num)) {
            mask = (mask << 1) | 1;
        }

        // XORing num with a mask of all 1s flips every bit: 1 ^ 1 = 0, 0 ^ 1 = 1
        return num ^ mask;
    }
};