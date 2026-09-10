#include <vector>
#include <algorithm>

class Solution {
public:
    int maxDistance(std::vector<int>& colors) {
        int n = colors.size();
        int max_dist = 0;

        // Check distance from the left boundary (index 0)
        for (int i = n - 1; i >= 0; --i) {
            if (colors[i] != colors[0]) {
                max_dist = std::max(max_dist, i);
                break;
            }
        }

        // Check distance from the right boundary (index n - 1)
        for (int i = 0; i < n; ++i) {
            if (colors[i] != colors[n - 1]) {
                max_dist = std::max(max_dist, (n - 1) - i);
                break;
            }
        }

        return max_dist;
    }
};