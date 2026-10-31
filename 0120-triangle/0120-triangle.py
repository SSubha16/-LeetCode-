from typing import List

class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        # Initialize DP list with the bottom row
        dp = list(triangle[-1])

        # Work upwards from the second-to-last row
        for i in range(len(triangle) - 2, -1, -1):
            for j in range(i + 1):
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1])

        return dp[0]