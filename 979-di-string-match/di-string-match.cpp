#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> diStringMatch(std::string s) {
        int n = s.length();
        int low = 0, high = n;
        std::vector<int> perm(n + 1);

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'I') {
                perm[i] = low++;
            } else {
                perm[i] = high--;
            }
        }
        // Place the last remaining number
        perm[n] = low;

        return perm;
    }
};