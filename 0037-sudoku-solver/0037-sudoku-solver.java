import java.util.ArrayList;
import java.util.List;

class Solution {
    private boolean[][] rows = new boolean[9][10];
    private boolean[][] cols = new boolean[9][10];
    private boolean[][] boxes = new boolean[9][10];
    private List<int[]> emptyCells = new ArrayList<>();

    public void solveSudoku(char[][] board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    emptyCells.add(new int[]{r, c});
                } else {
                    int digit = board[r][c] - '0';
                    int b = (r / 3) * 3 + (c / 3);
                    rows[r][digit] = true;
                    cols[c][digit] = true;
                    boxes[b][digit] = true;
                }
            }
        }

        backtrack(board, 0);
    }

    private boolean backtrack(char[][] board, int index) {
        if (index == emptyCells.size()) {
            return true;
        }

        int[] cell = emptyCells.get(index);
        int r = cell[0];
        int c = cell[1];
        int b = (r / 3) * 3 + (c / 3);

        for (int digit = 1; digit <= 9; digit++) {
            if (!rows[r][digit] && !cols[c][digit] && !boxes[b][digit]) {
                rows[r][digit] = true;
                cols[c][digit] = true;
                boxes[b][digit] = true;
                board[r][c] = (char) (digit + '0');

                if (backtrack(board, index + 1)) {
                    return true;
                }

                // Backtrack
                rows[r][digit] = false;
                cols[c][digit] = false;
                boxes[b][digit] = false;
                board[r][c] = '.';
            }
        }

        return false;
    }
}