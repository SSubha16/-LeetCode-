class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        // Initialize DP array with the last row
        int[] dp = new int[n];
        for (int j = 0; j < n; j++) {
            dp[j] = triangle.get(n - 1).get(j);
        }

        // Work upwards from the second to last row
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle.get(i).get(j) + Math.min(dp[j], dp[j + 1]);
            }
        }

        return dp[0];
    }
}