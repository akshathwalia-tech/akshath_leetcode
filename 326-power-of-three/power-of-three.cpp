class Solution {
public:
    // Helper function for 3^exp
    long long power(int base, int exp) {
        long long res = 1;
        long long b = base;
        while (exp > 0) {
            if (exp & 1) res *= b;
            b *= b;
            exp >>= 1;
        }
        return res;
    }

    bool isPowerOfThree(int n) {
        if (n <= 0) return false;

        int low = 0, high = 19;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long val = power(3, mid);

            if (val == n) {
                return true;
            } else if (val < n) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};