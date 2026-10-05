class Solution {
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int maxWater = 0;

        while (left < right) {
            int width = right - left;
            int currentArea;

            if (height[left] < height[right]) {
                currentArea = width * height[left];
                left++;
            } else {
                currentArea = width * height[right];
                right--;
            }

            if (currentArea > maxWater) {
                maxWater = currentArea;
            }
        }

        return maxWater;
    }
}