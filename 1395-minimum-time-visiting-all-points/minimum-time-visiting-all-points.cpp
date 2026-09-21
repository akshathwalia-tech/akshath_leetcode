#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points) {
        int total_time = 0;
        
        for (size_t i = 1; i < points.size(); ++i) {
            int dx = std::abs(points[i][0] - points[i - 1][0]);
            int dy = std::abs(points[i][1] - points[i - 1][1]);
            
            // Chebyshev distance: max(|x2 - x1|, |y2 - y1|)
            total_time += std::max(dx, dy);
        }
        
        return total_time;
    }
};