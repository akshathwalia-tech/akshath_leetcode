#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        std::unordered_map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        // Min-heap to keep track of smallest available cards
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        for (auto& [card, _] : count) {
            minHeap.push(card);
        }

        while (!minHeap.empty()) {
            int smallest = minHeap.top();

            // Skip elements that were already completely consumed
            if (count[smallest] == 0) {
                minHeap.pop();
                continue;
            }

            // Greedily consume the consecutive group
            for (int i = 0; i < groupSize; i++) {
                int nextCard = smallest + i;
                if (count[nextCard] == 0) {
                    return false;
                }
                count[nextCard]--;
            }
        }

        return true;
    }
};