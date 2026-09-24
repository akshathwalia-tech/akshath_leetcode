#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Track seen numbers [1-9] for 9 rows, 9 columns, and 9 sub-boxes (3x3)
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }

                // Map '1'-'9' to index 0-8
                int num = board[r][c] - '1';

                // Sub-box index formula: 3 * (r / 3) + (c / 3)
                int boxIndex = (r / 3) * 3 + (c / 3);

                // If already seen in the current row, column, or 3x3 sub-box
                if (rows[r][num] || cols[c][num] || boxes[boxIndex][num]) {
                    return false;
                }

                // Mark as seen
                rows[r][num] = true;
                cols[c][num] = true;
                boxes[boxIndex][num] = true;
            }
        }

        return true;
    }
};