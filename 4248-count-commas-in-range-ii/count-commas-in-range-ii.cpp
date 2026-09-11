class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;
        long long threshold = 1000; // 10^3

        while (n >= threshold) {
            totalCommas += (n - threshold + 1);
            
            // Check before multiplying to prevent overflow if threshold * 1000 > 10^18
            if (threshold > (long long)1e15 / 1000) {
                break;
            }
            threshold *= 1000;
        }

        return totalCommas;
    }
};