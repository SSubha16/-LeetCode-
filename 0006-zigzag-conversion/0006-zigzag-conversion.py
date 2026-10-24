class Solution:
    def convert(self, s: str, numRows: int) -> str:
        # Base case: no zigzag pattern possible
        if numRows == 1 or numRows >= len(s):
            return s

        # Create a list of strings for each row
        rows = [""] * min(len(s), numRows)
        cur_row = 0
        going_down = False

        # Traverse the string
        for char in s:
            rows[cur_row] += char
            # Reverse direction if we hit the top or bottom row
            if cur_row == 0 or cur_row == numRows - 1:
                going_down = not going_down
            
            cur_row += 1 if going_down else -1
            
        # Concatenate all rows
        return "".join(rows)