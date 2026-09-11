class Solution {
private:
    const int MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

public:
    int monkeyMove(int n) {
        // (2^n - 2) % MOD, adding MOD to prevent negative values
        long long totalMinusNoCollisions = (power(2, n) - 2 + MOD) % MOD;
        return totalMinusNoCollisions;
    }
};