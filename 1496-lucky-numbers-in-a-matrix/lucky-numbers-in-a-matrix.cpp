#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxRowMin = INT_MIN;
        for (int i = 0; i < m; ++i) {
            int rowMin = matrix[i][0];
            for (int j = 1; j < n; ++j) {
                rowMin = min(rowMin, matrix[i][j]);
            }
            maxRowMin = max(maxRowMin, rowMin);
        }

        int minColMax = INT_MAX;
        for (int j = 0; j < n; ++j) {
            int colMax = matrix[0][j];
            for (int i = 1; i < m; ++i) {
                colMax = max(colMax, matrix[i][j]);
            }
            minColMax = min(minColMax, colMax);
        }

        if (maxRowMin == minColMax) {
            return {maxRowMin};
        }
        return {};
    }
};