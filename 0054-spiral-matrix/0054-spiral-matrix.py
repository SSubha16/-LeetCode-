class Solution:
    def spiralOrder(self, matrix: list[list[int]]) -> list[int]:
        if not matrix:
            return []

        res = []
        top, bottom = 0, len(matrix) - 1
        left, right = 0, len(matrix[0]) - 1

        while top <= bottom and left <= right:
            # 1. Traverse Right
            for col in range(left, right + 1):
                res.append(matrix[top][col])
            top += 1

            # 2. Traverse Down
            for row in range(top, bottom + 1):
                res.append(matrix[row][right])
            right -= 1

            # Check boundaries before returning across bottom or up left
            if top <= bottom:
                # 3. Traverse Left
                for col in range(right, left - 1, -1):
                    res.append(matrix[bottom][col])
                bottom -= 1

            if left <= right:
                # 4. Traverse Up
                for row in range(bottom, top - 1, -1):
                    res.append(matrix[row][left])
                left += 1

        return res