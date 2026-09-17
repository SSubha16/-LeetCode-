from typing import List

class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        # A valid IPv4 string must have between 4 and 12 digits
        if len(s) < 4 or len(s) > 12:
            return []

        res = []

        def backtrack(start_idx: int, dots_placed: int, path: List[str]):
            # Base case: 4 segments placed
            if dots_placed == 4:
                if start_idx == len(s):
                    res.append(".".join(path))
                return

            # Try segment lengths 1, 2, and 3
            for length in range(1, 4):
                if start_idx + length > len(s):
                    break

                segment = s[start_idx : start_idx + length]

                # Check leading zero (e.g., "00", "01" are invalid)
                if len(segment) > 1 and segment[0] == "0":
                    break

                # Check range [0, 255]
                if int(segment) <= 255:
                    backtrack(start_idx + length, dots_placed + 1, path + [segment])

        backtrack(0, 0, [])
        return res