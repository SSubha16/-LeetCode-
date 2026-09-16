class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int m = board.size();
        int n = board[0].size();

        // Quick check: if the word is longer than the grid, it's impossible
        if (word.length() > m * n) return false;

        // Optimization: Frequency check
        std::unordered_map<char, int> board_count;
        for (const auto& row : board) {
            for (char ch : row) {
                board_count[ch]++;
            }
        }
        for (char ch : word) {
            if (--board_count[ch] < 0) return false;
        }

        // Optimization: Reverse word if the first character is more frequent than the last
        // This reduces branching early in the recursion tree.
        if (board_count[word.front()] > board_count[word.back()]) {
            std::reverse(word.begin(), word.end());
        }

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == word[0] && dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool dfs(std::vector<std::vector<char>>& board, const std::string& word, int r, int c, int idx) {
        if (idx == word.length()) return true;

        // Out of bounds or character mismatch
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[idx]) {
            return false;
        }

        // Mark cell as visited in-place
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore 4 adjacent directions: up, down, left, right
        bool found = dfs(board, word, r + 1, c, idx + 1) ||
                     dfs(board, word, r - 1, c, idx + 1) ||
                     dfs(board, word, r, c + 1, idx + 1) ||
                     dfs(board, word, r, c - 1, idx + 1);

        // Restore original character (backtrack)
        board[r][c] = temp;

        return found;
    }
};