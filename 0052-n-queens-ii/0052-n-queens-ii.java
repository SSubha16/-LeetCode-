class Solution {
    private int count = 0;

    public int totalNQueens(int n) {
        count = 0;
        // Bitmask with the lowest n bits set to 1
        int fullMask = (1 << n) - 1;
        backtrack(0, 0, 0, fullMask);
        return count;
    }

    private void backtrack(int cols, int diag1, int diag2, int fullMask) {
        // Base case: all columns are filled
        if (cols == fullMask) {
            count++;
            return;
        }

        // Available slots in the current row: 1 means available
        int availablePositions = fullMask & ~(cols | diag1 | diag2);

        while (availablePositions != 0) {
            // Pick the lowest set bit (rightmost valid column)
            int position = availablePositions & -availablePositions;

            // Clear the picked bit
            availablePositions &= (availablePositions - 1);

            // Recurse to the next row:
            // - cols tracks vertical conflicts
            // - (diag1 | position) << 1 shifts main diagonals down-left
            // - (diag2 | position) >>> 1 shifts anti-diagonals down-right
            backtrack(cols | position,
                      (diag1 | position) << 1,
                      (diag2 | position) >>> 1,
                      fullMask);
        }
    }
}