class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        int fullMask = (1 << n) - 1;
        
        auto backtrack = [&](auto& self, int row, int cols, int diag1, int diag2) -> void {
            if (row == n) {
                count++;
                return;
            }
            
            // Available spots where none of the bitmasks have a queen attacking
            int available = fullMask & ~(cols | diag1 | diag2);
            
            while (available) {
                // Extract the lowest set bit
                int bit = available & -available;
                
                // Remove the bit from available positions
                available &= available - 1;
                
                // Recurse to next row with updated masks
                self(self, row + 1, cols | bit, (diag1 | bit) << 1, (diag2 | bit) >> 1);
            }
        };
        
        backtrack(backtrack, 0, 0, 0, 0);
        return count;
    }
};