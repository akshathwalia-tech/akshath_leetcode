
class Solution {
public:
    // Function to return maximum score by picking k cards from either end
    int maxScore(vector<int>& cardPoints, int k) {
        // Get the total number of cards
        int n = cardPoints.size();

        // Calculate initial sum by picking first k cards from front
        int total = 0;
        for (int i = 0; i < k; ++i) {
            total += cardPoints[i];
        }

        // Store current max score
        int maxPoints = total;

        // Move the window from front to back k times
        for (int i = 0; i < k; ++i) {
            // Subtract card from front
            total -= cardPoints[k - 1 - i];

            // Add card from back
            total += cardPoints[n - 1 - i];

            // Update max score if needed
            maxPoints = max(maxPoints, total);
        }

        // Return the best score
        return maxPoints;
    }
};