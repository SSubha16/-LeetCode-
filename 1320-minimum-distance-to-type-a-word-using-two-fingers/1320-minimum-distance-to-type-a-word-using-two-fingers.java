import java.util.Arrays;

class Solution {
    private int dist(int a, int b) {
        if (a == 26) return 0; // Free initial placement
        return Math.abs(a / 6 - b / 6) + Math.abs(a % 6 - b % 6);
    }

    public int minimumDistance(String word) {
        int n = word.length();
        // dp[c] stores the minimum cost when the other finger is at character c (26 = unused)
        int[] dp = new int[27];
        Arrays.fill(dp, Integer.MAX_VALUE / 2);
        dp[26] = 0;

        for (int i = 0; i < n - 1; i++) {
            int cur = word.charAt(i) - 'A';
            int next = word.charAt(i + 1) - 'A';
            int moveSame = dist(cur, next);

            int[] nextDp = new int[27];
            Arrays.fill(nextDp, Integer.MAX_VALUE / 2);

            for (int other = 0; other <= 26; other++) {
                if (dp[other] >= Integer.MAX_VALUE / 2) continue;

                // Option 1: The finger currently at 'cur' types 'next'
                // The 'other' finger remains at 'other'
                nextDp[other] = Math.min(nextDp[other], dp[other] + moveSame);

                // Option 2: The 'other' finger types 'next'
                // The finger that was at 'cur' now becomes the 'other' finger
                int moveOther = dist(other, next);
                nextDp[cur] = Math.min(nextDp[cur], dp[other] + moveOther);
            }

            dp = nextDp;
        }

        int minCost = Integer.MAX_VALUE;
        for (int cost : dp) {
            minCost = Math.min(minCost, cost);
        }

        return minCost;
    }
}