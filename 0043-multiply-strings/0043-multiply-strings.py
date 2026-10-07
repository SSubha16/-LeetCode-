class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        # Edge case: multiplication by zero
        if num1 == "0" or num2 == "0":
            return "0"

        m, n = len(num1), len(num2)
        res = [0] * (m + n)

        # Traverse from right to left (least significant to most significant)
        for i in range(m - 1, -1, -1):
            d1 = ord(num1[i]) - ord('0')
            for j in range(n - 1, -1, -1):
                d2 = ord(num2[j]) - ord('0')
                
                mul = d1 * d2
                p1, p2 = i + j, i + j + 1
                total = mul + res[p2]

                res[p2] = total % 10
                res[p1] += total // 10

        # Skip leading zero if present
        start_idx = 0
        while start_idx < len(res) and res[start_idx] == 0:
            start_idx += 1

        return "".join(map(str, res[start_idx:]))