class Solution:
    def minimumTotalDistance(self, robot: list[int], factory: list[list[int]]) -> int:
        robot.sort()
        factory.sort(key=lambda f: f[0])
        
        # Flatten factory positions by their capacity
        slots = []
        for pos, limit in factory:
            slots.extend([pos] * limit)
            
        n = len(robot)
        m = len(slots)
        
        # dp[i] = min distance to cover the first i robots
        dp = [float('inf')] * (n + 1)
        dp[0] = 0
        
        for slot_pos in slots:
            # Iterate backwards to reuse 1D DP table
            for i in range(n, 0, -1):
                if dp[i - 1] != float('inf'):
                    dp[i] = min(dp[i], dp[i - 1] + abs(robot[i - 1] - slot_pos))
                    
        return dp[n]