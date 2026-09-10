#include <vector>
#include <algorithm>

class Solution {
public:
    int maxDistance(std::vector<int>& nums1, std::vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int max_dist = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();

        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) {
                max_dist = std::max(max_dist, j - i);
                j++; // Try to expand the distance
            } else {
                i++; // nums1[i] is too large, move to a smaller element
            }
        }

        return max_dist;
    }
};