class Solution:
    def minimumTotalDistance(
        self, robot: list[int], factory: list[list[int]]
    ) -> int:
        robot.sort()
        factory.sort(key=lambda x: x[0])

        # Flatten factories into individual slots (at most len(robot) slots per factory)
        n = len(robot)
        slots = []
        for pos, limit in factory:
            slots.extend([pos] * min(limit, n))

        m = len(slots)

        # dp[i] = minimum distance to assign the first i robots
        dp = [float("inf")] * (n + 1)
        dp[0] = 0

        # Iterate over each factory slot
        for slot_pos in slots:
            # Update backwards so each slot can only be used by at most one robot
            for i in range(n, 0, -1):
                if dp[i - 1] != float("inf"):
                    dp[i] = min(dp[i], dp[i - 1] + abs(robot[i - 1] - slot_pos))

        return dp[n]