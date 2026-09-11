from typing import List


class Solution:

  def minOperations(self, grid: List[List[int]], x: int) -> int:
    # Flatten grid into a 1D list
    nums = [val for row in grid for val in row]

    # Verify if all numbers share the same remainder modulo x
    base_rem = nums[0] % x
    for val in nums:
      if val % x != base_rem:
        return -1

    # Sort to find the median
    nums.sort()
    median = nums[len(nums) // 2]

    # Calculate operations to bring each element to the median
    return sum(abs(val - median) // x for val in nums)