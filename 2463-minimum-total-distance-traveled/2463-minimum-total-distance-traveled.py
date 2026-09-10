class Solution:
    def minimumTotalDistance(self, robot: list[int], factory: list[list[int]]) -> int:
        robot.sort()
        factory.sort()

        # Expand factories into individual repair slots
        factory_slots = []
        for pos, limit in factory:
            factory_slots.extend([pos] * limit)

        n = len(robot)
        m = len(factory_slots)

        # dp[i] represents the minimum distance to repair the first i robots
        dp = [float('inf')] * (n + 1)
        dp[0] = 0

        # Process one factory slot at a time (space-optimized 1D DP)
        for slot in factory_slots:
            for i in range(n, 0, -1):
                if dp[i - 1] != float('inf'):
                    dp[i] = min(dp[i], dp[i - 1] + abs(robot[i - 1] - slot))

        return dp[n]