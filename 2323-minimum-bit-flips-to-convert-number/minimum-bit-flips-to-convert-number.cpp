class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xor_val = start ^ goal;
        int count = 0;
        
        while (xor_val > 0) {
            xor_val &= (xor_val - 1);
            count++;
        }
        
        return count;
    }
};