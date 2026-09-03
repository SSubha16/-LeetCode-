#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Step 1: Find the first decreasing element from the right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Step 2: If such an element is found, find the element just larger than nums[i] to its right
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            std::swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the sequence from i + 1 to the end to get the smallest lexicographical order
        std::reverse(nums.begin() + i + 1, nums.end());
    }
};