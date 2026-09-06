class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }

        // Pointer for placing the next unique element
        int k = 1;

        for (int i = 1; i < nums.length; i++) {
            // Found a new unique element
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
}