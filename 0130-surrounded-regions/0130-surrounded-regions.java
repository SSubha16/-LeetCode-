class Solution {
    public void solve(char[][] board) {
        if (board == null || board.length == 0) {
            return;
        }
        
        int rows = board.length;
        int cols = board[0].length;
        
        // 1. Traverse left and right borders
        for (int r = 0; r < rows; r++) {
            if (board[r][0] == 'O') dfs(board, r, 0, rows, cols);
            if (board[r][cols - 1] == 'O') dfs(board, r, cols - 1, rows, cols);
        }
        
        // 2. Traverse top and bottom borders
        for (int c = 0; c < cols; c++) {
            if (board[0][c] == 'O') dfs(board, 0, c, rows, cols);
            if (board[rows - 1][c] == 'O') dfs(board, rows - 1, c, rows, cols);
        }
        
        // 3. Capture surrounded regions and restore safe regions
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == '#') {
                    board[r][c] = 'O';
                }
            }
        }
    }
    
    private void dfs(char[][] board, int r, int c, int rows, int cols) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'O') {
            return;
        }
        
        board[r][c] = '#'; // Mark as safe
        dfs(board, r + 1, c, rows, cols);
        dfs(board, r - 1, c, rows, cols);
        dfs(board, r, c + 1, rows, cols);
        dfs(board, r, c - 1, rows, cols);
    }
}