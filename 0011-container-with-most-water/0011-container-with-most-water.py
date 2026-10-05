class Solution:
    def maxArea(self, height: list[int]) -> int:
        left = 0
        right = len(height) - 1
        max_water = 0

        while left < right:
            width = right - left
            # Limiting height determines the capacity
            if height[left] < height[right]:
                current_area = width * height[left]
                left += 1
            else:
                current_area = width * height[right]
                right -= 1

            if current_area > max_water:
                max_water = current_area

        return max_water