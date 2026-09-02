#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }

        int k = 2; // Pointer where the next valid element should be placed

        for (int i = 2; i < nums.size(); ++i) {
            // If the current element is different from the element at k - 2,
            // it means we haven't added this element twice yet.
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};