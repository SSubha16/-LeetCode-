class Solution:
    def closestTarget(self, words: list[str], target: str, startIndex: int) -> int:
        n = len(words)
        min_dist = float('inf')

        for i, word in enumerate(words):
            if word == target:
                direct_dist = abs(i - startIndex)
                circular_dist = min(direct_dist, n - direct_dist)
                min_dist = min(min_dist, circular_dist)

        return min_dist if min_dist != float('inf') else -1