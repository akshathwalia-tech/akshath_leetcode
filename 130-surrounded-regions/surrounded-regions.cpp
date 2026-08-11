class Solution {
public:
       void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& mat, int delrow[], int delcol[]) {
        // mark current cell visited
        vis[row][col] = 1;
        // cache dimensions
        int n = mat.size(), m = mat[0].size();
        // try 4 directions
        for (int k = 0; k < 4; k++) {
            // compute next cell
            int nrow = row + delrow[k], ncol = col + delcol[k];
            // check bounds and unvisited 'O'
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
                // continue DFS
                dfs(nrow, ncol, vis, mat, delrow, delcol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        if (n == 0 || m == 0) return;
        // direction arrays for 4-neighbors
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        // visited matrix
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // traverse first and last row
        for (int j = 0; j < m; j++) {
            // start DFS from unvisited boundary 'O' (top row)
            if (!vis[0][j] && board[0][j] == 'O') dfs(0, j, vis, board, delrow, delcol);
            // start DFS from unvisited boundary 'O' (bottom row)
            if (!vis[n - 1][j] && board[n - 1][j] == 'O') dfs(n - 1, j, vis, board, delrow, delcol);
        }

        // traverse first and last column
        for (int i = 0; i < n; i++) {
            // start DFS from unvisited boundary 'O' (left col)
            if (!vis[i][0] && board[i][0] == 'O') dfs(i, 0, vis, board, delrow, delcol);
            // start DFS from unvisited boundary 'O' (right col)
            if (!vis[i][m - 1] && board[i][m - 1] == 'O') dfs(i, m - 1, vis, board, delrow, delcol);
        }

        // flip all unvisited 'O' to 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // convert enclosed 'O' to 'X'
                if (!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }

        // return updated board
        return ;
    }
};