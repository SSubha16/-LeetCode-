import java.util.HashMap;
import java.util.Map;

class Solution {
    public int minMirrorPairDistance(int[] nums) {
        int n = nums.length;
        int minDistance = Integer.MAX_VALUE;
        
        // Maps reversed value -> latest seen index
        Map<Integer, Integer> latestIndex = new HashMap<>();

        for (int i = 0; i < n; i++) {
            // Check if any previous number's reverse matches current nums[i]
            if (latestIndex.containsKey(nums[i])) {
                minDistance = Math.min(minDistance, i - latestIndex.get(nums[i]));
            }

            // Register this element's reverse so future elements can match against it
            int reversedVal = reverse(nums[i]);
            latestIndex.put(reversedVal, i);
        }

        return minDistance == Integer.MAX_VALUE ? -1 : minDistance;
    }

    private int reverse(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }
}