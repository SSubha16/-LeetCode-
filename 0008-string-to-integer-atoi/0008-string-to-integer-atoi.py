class Solution:
    def myAtoi(self, s: str) -> int:
        i = 0
        n = len(s)
        
        # 1. Skip leading whitespace
        while i < n and s[i] == ' ':
            i += 1
            
        if i == n:
            return 0
        
        # 2. Check sign
        sign = 1
        if s[i] == '-':
            sign = -1
            i += 1
        elif s[i] == '+':
            i += 1
            
        # 3. Read digits manually
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31
        result = 0
        
        while i < n and '0' <= s[i] <= '9':
            digit = ord(s[i]) - ord('0')
            
            # Check overflow before multiplying
            if result > INT_MAX // 10 or (result == INT_MAX // 10 and digit > (7 if sign == 1 else 8)):
                return INT_MAX if sign == 1 else INT_MIN
            
            result = result * 10 + digit
            i += 1
            
        return sign * result