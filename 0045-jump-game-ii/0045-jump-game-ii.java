class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        if (n <= 1) {
            return 0;
        }

        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        // Iterate up to n - 2 because reaching or crossing n - 1 is the goal
        for (int i = 0; i < n - 1; i++) {
            farthest = Math.max(farthest, i + nums[i]);

            // When reaching the end of the current jump boundary
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;

                // Early exit if the target is already reachable
                if (currentEnd >= n - 1) {
                    break;
                }
            }
        }

        return jumps;
    }
}