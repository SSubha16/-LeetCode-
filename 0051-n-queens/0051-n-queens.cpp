#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> solutions;
        std::vector<std::string> board(n, std::string(n, '.'));

        // Lookup trackers for O(1) conflict checks
        std::vector<bool> cols(n, false);
        std::vector<bool> diag1(2 * n - 1, false); // row - col + (n - 1)
        std::vector<bool> diag2(2 * n - 1, false); // row + col

        backtrack(0, n, board, cols, diag1, diag2, solutions);
        return solutions;
    }

private:
    void backtrack(int row, int n,
                   std::vector<std::string>& board,
                   std::vector<bool>& cols,
                   std::vector<bool>& diag1,
                   std::vector<bool>& diag2,
                   std::vector<std::vector<std::string>>& solutions) {
        if (row == n) {
            solutions.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            int d1 = row - col + n - 1;
            int d2 = row + col;

            if (cols[col] || diag1[d1] || diag2[d2]) {
                continue;
            }

            // Place queen
            board[row][col] = 'Q';
            cols[col] = diag1[d1] = diag2[d2] = true;

            // Move to next row
            backtrack(row + 1, n, board, cols, diag1, diag2, solutions);

            // Revert state
            board[row][col] = '.';
            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }
};