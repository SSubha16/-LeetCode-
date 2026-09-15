class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)

        # dp[j] stores the edit distance to word2[:j]
        # Space-optimized to O(n) using a 1D array
        dp = list(range(n + 1))

        for i in range(1, m + 1):
            prev = dp[0]
            dp[0] = i  # Deleting all characters from word1[:i] to match ""
            for j in range(1, n + 1):
                temp = dp[j]
                if word1[i - 1] == word2[j - 1]:
                    dp[j] = prev
                else:
                    dp[j] = 1 + min(
                        dp[j],      # Delete from word1
                        dp[j - 1],  # Insert into word1
                        prev        # Replace character
                    )
                prev = temp

        return dp[n]