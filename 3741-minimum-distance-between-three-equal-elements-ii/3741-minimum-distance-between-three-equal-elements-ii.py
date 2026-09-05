from collections import defaultdict

class Solution:
    def minimumDistance(self, nums: list[int]) -> int:
        indices = defaultdict(list)
        min_dist = float('inf')
        
        for idx, val in enumerate(nums):
            pos = indices[val]
            pos.append(idx)
            
            # Whenever we have at least 3 occurrences, check the distance
            # between the current index and the index 2 positions back
            if len(pos) >= 3:
                dist = 2 * (pos[-1] - pos[-3])
                if dist < min_dist:
                    min_dist = dist
                    
        return min_dist if min_dist != float('inf') else -1