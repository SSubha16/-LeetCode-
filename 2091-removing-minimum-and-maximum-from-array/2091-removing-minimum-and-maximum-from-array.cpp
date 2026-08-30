#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumDeletions(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int minIdx = 0;
        int maxIdx = 0;

        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }

        // Ensure leftIdx <= rightIdx for simpler boundary calculation
        int leftIdx = std::min(minIdx, maxIdx);
        int rightIdx = std::max(minIdx, maxIdx);

        // Strategy 1: Delete both from the front
        int frontOnly = rightIdx + 1;

        // Strategy 2: Delete both from the back
        int backOnly = n - leftIdx;

        // Strategy 3: Delete the left one from the front and the right one from the back
        int bothSides = (leftIdx + 1) + (n - rightIdx);

        return std::min({frontOnly, backOnly, bothSides});
    }
};