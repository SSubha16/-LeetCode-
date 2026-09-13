class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[] dp = new int[n];

        dp[0] = grid[0][0];

        // Initialize first row (can only come from the left)
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j - 1] + grid[0][j];
        }

        // Fill remaining rows
        for (int i = 1; i < m; i++) {
            dp[0] += grid[i][0]; // First column can only come from above
            for (int j = 1; j < n; j++) {
                // dp[j] is top, dp[j - 1] is left
                dp[j] = grid[i][j] + Math.min(dp[j], dp[j - 1]);
            }
        }

        return dp[n - 1];
    }
}