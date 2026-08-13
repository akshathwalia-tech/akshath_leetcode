#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Check if start or end is blocked (Note: 0 = clear, 1 = blocked in LC 1091)
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) {
            return -1;
        }

        if (n == 1 && m == 1) return 1; // Base case for 1x1 grid

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = 1; // Path length starts at 1
        q.push({1, {0, 0}}); // Fix 2: Wrap pair in braces

        // 8 directions (Up, Down, Left, Right, 4 Diagonals)
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for (int i = 0; i < 8; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];

                // Check bounds, check if passable cell (0), and if shorter path found
                if (newr >= 0 && newr < n && newc >= 0 && newc < m && 
                    grid[newr][newc] == 0 && dis + 1 < dist[newr][newc]) {
                    
                    dist[newr][newc] = dis + 1; // Fix 3: Use '=' instead of '=='

                    // Fix 4: Check destination INSIDE validity block
                    if (newr == n - 1 && newc == m - 1) {
                        return dis + 1;
                    }

                    q.push({dis + 1, {newr, newc}}); // Fix 4: Push inside validity block
                }
            }
        }

        return -1;
    }
};