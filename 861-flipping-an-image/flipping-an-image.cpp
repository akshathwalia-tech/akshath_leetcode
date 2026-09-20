#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& image) {
        int n = image.size();
        
        for (int r = 0; r < n; ++r) {
            int left = 0;
            int right = n - 1;
            
            while (left <= right) {
                if (left == right) {
                    // Middle element in an odd-length row: only invert
                    image[r][left] ^= 1;
                } else if (image[r][left] == image[r][right]) {
                    // If both values are equal, swapping them doesn't change their values,
                    // but inverting both flips them (0 -> 1 or 1 -> 0).
                    image[r][left] ^= 1;
                    image[r][right] ^= 1;
                }
                // If image[r][left] != image[r][right]:
                // Swapping makes them opposite, and then inverting flips them back
                // to the original values, so no change is needed.

                left++;
                right--;
            }
        }
        
        return image;
    }
};