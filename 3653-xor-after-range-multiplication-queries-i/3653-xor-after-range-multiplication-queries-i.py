from functools import reduce
from operator import xor

class Solution:
    def xorAfterQueries(self, nums: list[int], queries: list[list[int]]) -> int:
        MOD = 1_000_000_007
        
        # Process each query directly
        for l, r, k, v in queries:
            for idx in range(l, r + 1, k):
                nums[idx] = (nums[idx] * v) % MOD
        
        # Compute the XOR sum of all elements
        return reduce(xor, nums)