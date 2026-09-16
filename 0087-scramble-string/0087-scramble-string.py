from functools import cache

class Solution:
    @cache
    def isScramble(self, s1: str, s2: str) -> bool:
        if s1 == s2:
            return True
        # Prune branches early if character counts do not match
        if sorted(s1) != sorted(s2):
            return False

        n = len(s1)
        for i in range(1, n):
            # Case 1: Substrings are NOT swapped
            # s1[:i] matches s2[:i] AND s1[i:] matches s2[i:]
            if self.isScramble(s1[:i], s2[:i]) and self.isScramble(s1[i:], s2[i:]):
                return True

            # Case 2: Substrings ARE swapped
            # s1[:i] matches s2[n-i:] AND s1[i:] matches s2[:n-i]
            if self.isScramble(s1[:i], s2[n - i:]) and self.isScramble(s1[i:], s2[:n - i]):
                return True

        return False