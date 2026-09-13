from typing import List


class Solution:

  def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
    # If the start or target cell is blocked, no path is possible
    if obstacleGrid[0][0] == 1 or obstacleGrid[-1][-1] == 1:
      return 0

    m, n = len(obstacleGrid), len(obstacleGrid[0])
    dp = [0] * n
    dp[0] = 1

    for i in range(m):
      for j in range(n):
        if obstacleGrid[i][j] == 1:
          dp[j] = 0
        elif j > 0:
          # dp[j] holds paths from above; dp[j - 1] holds paths from the left
          dp[j] += dp[j - 1]

    return dp[-1]