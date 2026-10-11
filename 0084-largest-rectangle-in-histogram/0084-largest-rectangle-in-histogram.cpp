#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; ++i) {
            // Use 0 as a sentinel height after processing all bars
            int currentHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && currentHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();

                // If stack is empty, it spans all the way to index 0 (width = i)
                int width = st.empty() ? i : (i - st.top() - 1);
                maxArea = std::max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};