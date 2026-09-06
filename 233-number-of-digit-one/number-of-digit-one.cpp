class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;

        long long count = 0;
        long long m = 1; // Place value: 1, 10, 100, ...

        while (m <= n) {
            long long high = n / (m * 10);
            long long cur = (n / m) % 10;
            long long low = n % m;

            if (cur == 0) {
                count += high * m;
            } else if (cur == 1) {
                count += high * m + (low + 1);
            } else {
                count += (high + 1) * m;
            }

            m *= 10;
        }

        return count;
    }
};