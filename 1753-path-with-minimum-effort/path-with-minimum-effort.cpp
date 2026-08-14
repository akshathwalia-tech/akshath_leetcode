
class Solution {
public:
    // Method to calculate the minimum effort path using Dijkstra's algorithm
    int minimumEffortPath(vector<vector<int>> &heights) {

        // Create a priority queue to store the cells and their respective distance from the source
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        int n = heights.size();  // Number of rows
        int m = heights[0].size();  // Number of columns

        // Create a distance matrix, initialized with a large value (unvisited)
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;  // Distance for the source cell (0, 0) is 0
        pq.push({0, {0, 0}});  // Push source cell to the priority queue

        // Define the possible directions (up, right, down, left)
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Start the Dijkstra algorithm
        while (!pq.empty()) {
            auto it = pq.top();  // Get the cell with the minimum distance
            pq.pop();
            int diff = it.first;  // The current effort
            int row = it.second.first;
            int col = it.second.second;

            // If we reach the destination cell, return the current effort
            if (row == n - 1 && col == m - 1)
                return diff;

            // Check all 4 possible adjacent cells
            for (int i = 0; i < 4; i++) {
                int newr = row + dr[i];
                int newc = col + dc[i];

                // Check if the new cell is within bounds
                if (newr >= 0 && newc >= 0 && newr < n && newc < m) {
                    // Calculate the effort required to move to the new cell
                    int newEffort = max(abs(heights[row][col] - heights[newr][newc]), diff);

                    // If the calculated effort is less, update and push to the queue
                    if (newEffort < dist[newr][newc]) {
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }
        return 0;  // If unreachable (although it should not reach here)
    }
};
