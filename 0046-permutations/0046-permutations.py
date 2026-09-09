class Solution:
    def permute(self, nums: list[int]) -> list[list[int]]:
        res = []

        def backtrack(start: int):
            # Base case: if start index reaches the end, record current arrangement
            if start == len(nums):
                res.append(nums[:])
                return

            for i in range(start, len(nums)):
                # Choose: place nums[i] at the start position
                nums[start], nums[i] = nums[i], nums[start]

                # Explore: recursively permute the rest of the array
                backtrack(start + 1)

                # Un-choose (Backtrack): revert swap for other branches
                nums[start], nums[i] = nums[i], nums[start]

        backtrack(0)
        return res