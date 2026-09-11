#include <vector>
#include <numeric>

class Solution {
public:
    int findTheWinner(int n, int k) {
        std::vector<int> friends(n);
        // Fill with 1, 2, ..., n
        std::iota(friends.begin(), friends.end(), 1);

        int currentIndex = 0;
        while (friends.size() > 1) {
            // Step k - 1 from current position, wrapped around remaining size
            currentIndex = (currentIndex + (k - 1)) % friends.size();
            friends.erase(friends.begin() + currentIndex);
        }

        return friends[0];
    }
};