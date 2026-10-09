class Solution:
    def jump(self, nums: list[int]) -> int:
        n = len(nums)
        if n <= 1:
            return 0

        jumps = 0
        current_end = 0
        farthest = 0

        # Only iterate up to n - 2
        for i in range(n - 1):
            farthest = max(farthest, i + nums[i])

            # Reached the boundary of the current jump level
            if i == current_end:
                jumps += 1
                current_end = farthest

                # Early exit if the end can already be reached
                if current_end >= n - 1:
                    break

        return jumps