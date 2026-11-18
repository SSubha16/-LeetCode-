# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.max_sum = float('-inf')

        def max_gain(node: Optional[TreeNode]) -> int:
            if not node:
                return 0

            # Ignore paths with negative sums
            left_gain = max(max_gain(node.left), 0)
            right_gain = max(max_gain(node.right), 0)

            # Price of a path arching through the current node
            current_path_sum = node.val + left_gain + right_gain

            # Update global maximum
            self.max_sum = max(self.max_sum, current_path_sum)

            # Return max gain if continuing the path up to the parent
            return node.val + max(left_gain, right_gain)

        max_gain(root)
        return self.max_sum