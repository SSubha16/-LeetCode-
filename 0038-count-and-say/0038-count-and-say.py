class Solution:
    def countAndSay(self, n: int) -> str:
        s = "1"
        
        for _ in range(n - 1):
            next_seq = []
            i = 0
            
            while i < len(s):
                count = 1
                # Count consecutive identical characters
                while i + 1 < len(s) and s[i] == s[i + 1]:
                    i += 1
                    count += 1
                
                next_seq.append(str(count))
                next_seq.append(s[i])
                i += 1
                
            s = "".join(next_seq)
            
        return s