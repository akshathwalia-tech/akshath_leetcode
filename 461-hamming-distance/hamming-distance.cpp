class Solution {
public:
    int hammingDistance(int x, int y) {
        int xor_val = x ^ y;
        int count = 0;
        
        // Brian Kernighan's Algorithm to count set bits
        while (xor_val > 0) {
            xor_val &= (xor_val - 1);
            count++;
        }
        
        return count;
    }
};