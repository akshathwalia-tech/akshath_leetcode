#include <vector>
#include <cstdint>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        // Using uint8_t avoids vector<bool> bit-proxy overhead
        vector<uint8_t> isPrime(n, 1);
        isPrime[0] = isPrime[1] = 0;

        // Only sieve odd numbers
        for (int i = 3; (long long)i * i < n; i += 2) {
            if (isPrime[i]) {
                // Step by 2*i to only mark odd multiples (e.g., 9, 15, 21...)
                for (int j = i * i; j < n; j += 2 * i) {
                    isPrime[j] = 0;
                }
            }
        }

        // Count prime 2, then count all odd primes
        int count = 1; // for prime 2
        for (int i = 3; i < n; i += 2) {
            if (isPrime[i]) {
                count++;
            }
        }

        return count;
    }
};