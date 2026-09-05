class Solution:
    def solveSudoku(self, board: list[list[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rows = [0] * 9
        cols = [0] * 9
        boxes = [0] * 9
        empty_cells = []

        # Initialize existing values and collect empty cells
        for r in range(9):
            for c in range(9):
                if board[r][c] == ".":
                    empty_cells.append((r, c))
                else:
                    digit = int(board[r][c])
                    mask = 1 << digit
                    box_idx = (r // 3) * 3 + (c // 3)
                    rows[r] |= mask
                    cols[c] |= mask
                    boxes[box_idx] |= mask

        def backtrack(index: int) -> bool:
            if index == len(empty_cells):
                return True

            r, c = empty_cells[index]
            box_idx = (r // 3) * 3 + (c // 3)

            # Mask of all used numbers in the current row, column, and box
            used = rows[r] | cols[c] | boxes[box_idx]

            for digit in range(1, 10):
                mask = 1 << digit
                if not (used & mask):
                    # Place digit
                    board[r][c] = str(digit)
                    rows[r] |= mask
                    cols[c] |= mask
                    boxes[box_idx] |= mask

                    if backtrack(index + 1):
                        return True

                    # Undo placement (backtrack)
                    rows[r] ^= mask
                    cols[c] ^= mask
                    boxes[box_idx] ^= mask
                    board[r][c] = "."

            return False

        backtrack(0)