class Solution {
private:
    const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
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
    int minNonZeroProduct(int p) {
        if (p == 1) return 1;

        // maxVal = 2^p - 1
        long long maxVal = (1ULL << p) - 1;
        
        // base = 2^p - 2
        long long base = (maxVal - 1) % MOD;
        
        // exponent = 2^(p-1) - 1
        long long exp = (1ULL << (p - 1)) - 1;

        long long powerPart = modPow(base, exp);
        long long ans = (powerPart * (maxVal % MOD)) % MOD;

        return ans;
    }
};