#include <vector>

class Solution {
    bool rows[9][10] = {false};
    bool cols[9][10] = {false};
    bool boxes[9][10] = {false};
    std::vector<std::pair<int, int>> emptyCells;

    bool backtrack(std::vector<std::vector<char>>& board, int index) {
        if (index == emptyCells.size()) {
            return true;
        }

        auto [r, c] = emptyCells[index];
        int b = (r / 3) * 3 + (c / 3);

        for (int digit = 1; digit <= 9; ++digit) {
            if (!rows[r][digit] && !cols[c][digit] && !boxes[b][digit]) {
                rows[r][digit] = cols[c][digit] = boxes[b][digit] = true;
                board[r][c] = digit + '0';

                if (backtrack(board, index + 1)) {
                    return true;
                }

                // Backtrack
                rows[r][digit] = cols[c][digit] = boxes[b][digit] = false;
                board[r][c] = '.';
            }
        }

        return false;
    }

public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    emptyCells.emplace_back(r, c);
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
};