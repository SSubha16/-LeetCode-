from typing import List


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []  # Stores indices of histogram bars
        max_area = 0
        # Append a 0-height sentinel to flush remaining bars in the stack at the end
        heights.append(0)

        for i, h in enumerate(heights):
            while stack and heights[stack[-1]] > h:
                # The bar popped is the height of the rectangle
                height = heights[stack.pop()]
                # If stack is empty, it extends all the way to the start (width = i)
                # Otherwise, width is bounded by the new stack top and current index i
                width = i if not stack else i - stack[-1] - 1
                max_area = max(max_area, height * width)

            stack.append(i)

        # Restore original list state
        heights.pop()
        return max_area