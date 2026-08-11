#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c, int m, int n) {
        // Base checks: boundary limits and water ('0')
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '0') {
            return;
        }

        // Sink the land (mark as visited directly in grid to save O(m*n) space)
        grid[r][c] = '0';

        // Direction vectors for 4 directions: Right, Left, Down, Up
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        // Recurse for all 4 adjacent neighbors
        for (int i = 0; i < 4; i++) {
            dfs(grid, r + dx[i], c + dy[i], m, n);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If an unvisited land cell is found, a new island starts
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j, m, n); // Sinks the entire connected island
                }
            }
        }

        return islands;
    }
};