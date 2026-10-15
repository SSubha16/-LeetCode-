class Solution:
    def totalNQueens(self, n: int) -> int:
        count = 0
        full_mask = (1 << n) - 1
        
        def backtrack(row: int, cols: int, diag1: int, diag2: int) -> None:
            nonlocal count
            if row == n:
                count += 1
                return
            
            # Find available positions in the current row
            available = full_mask & ~(cols | diag1 | diag2)
            
            while available:
                # Isolate the lowest set bit
                bit = available & -available
                # Clear the lowest set bit
                available &= available - 1
                # Move to next row with shifted diagonal masks
                backtrack(row + 1, cols | bit, (diag1 | bit) << 1, (diag2 | bit) >> 1)
        
        backtrack(0, 0, 0, 0)
        return count