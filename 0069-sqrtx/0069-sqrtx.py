class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0:
            return 0
            
        left, right = 1, x
        ans = 0
        
        while left <= right:
            mid = left + (right - left) // 2
            
            if mid * mid <= x:
                ans = mid         # mid is a valid candidate
                left = mid + 1    # try to find a larger integer
            else:
                right = mid - 1   # mid * mid is too large
                
        return ans