from collections import defaultdict

class Solution:
    def minimumDistance(self, nums: list[int]) -> int:
        indices = defaultdict(list)
        for idx, val in enumerate(nums):
            indices[val].append(idx)
            
        min_dist = float('inf')
        
        for idx_list in indices.values():
            if len(idx_list) >= 3:
                # Check consecutive triplets (i, j, k)
                for t in range(len(idx_list) - 2):
                    dist = 2 * (idx_list[t + 2] - idx_list[t])
                    if dist < min_dist:
                        min_dist = dist
                        
        return min_dist if min_dist != float('inf') else -1