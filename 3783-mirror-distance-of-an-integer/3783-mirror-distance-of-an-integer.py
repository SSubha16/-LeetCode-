class Solution:
    def mirrorDistance(self, n: int) -> int:
        temp = n
        reversed_n = 0
        while temp > 0:
            reversed_n = reversed_n * 10 + (temp % 10)
            temp //= 10
        
        return abs(n - reversed_n)