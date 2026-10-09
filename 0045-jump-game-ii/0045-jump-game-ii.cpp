#include <vector>
#include <algorithm>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int jumps = 0;
        int current_end = 0;
        int farthest = 0;

        // Iterate up to n - 2
        for (int i = 0; i < n - 1; ++i) {
            farthest = std::max(farthest, i + nums[i]);

            // Reached the boundary of the current jump level
            if (i == current_end) {
                ++jumps;
                current_end = farthest;

                // Early exit if the destination is already reachable
                if (current_end >= n - 1) {
                    break;
                }
            }
        }

        return jumps;
    }
};