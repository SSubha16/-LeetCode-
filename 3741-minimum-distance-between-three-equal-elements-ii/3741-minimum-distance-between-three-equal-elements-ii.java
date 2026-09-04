import java.util.Arrays;

class Solution {
    public int minimumDistance(int[] nums) {
        int n = nums.length;
        // prev1[v] stores the most recent index where value v appeared
        int[] prev1 = new int[n + 1];
        // prev2[v] stores the second most recent index where value v appeared
        int[] prev2 = new int[n + 1];
        
        Arrays.fill(prev1, -1);
        Arrays.fill(prev2, -1);

        int minDiff = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            int val = nums[i];

            // If we have seen this value at least twice before
            if (prev2[val] != -1) {
                minDiff = Math.min(minDiff, i - prev2[val]);
            }

            // Shift history for val
            prev2[val] = prev1[val];
            prev1[val] = i;
        }

        return (minDiff == Integer.MAX_VALUE) ? -1 : 2 * minDiff;
    }
}