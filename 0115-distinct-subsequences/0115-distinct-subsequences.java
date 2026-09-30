class Solution {
    public int numDistinct(String s, String t) {
        int m = s.length();
        int n = t.length();

        if (m < n) {
            return 0;
        }

        // dp[j] represents the number of subsequences matching t[0..j-1]
        long[] dp = new long[n + 1];
        dp[0] = 1; // Empty target matches 1 empty subsequence

        for (int i = 0; i < m; i++) {
            char charS = s.charAt(i);
            // Iterate backwards to update in-place without using extra space
            for (int j = n; j >= 1; j--) {
                if (charS == t.charAt(j - 1)) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return (int) dp[n];
    }
}