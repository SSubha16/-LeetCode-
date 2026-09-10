# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        matching_nodes = 0

        def post_order(node):
            nonlocal matching_nodes
            if not node:
                # (subtree_sum, subtree_node_count)
                return 0, 0

            # Compute sum and count of left and right subtrees
            left_sum, left_count = post_order(node.left)
            right_sum, right_count = post_order(node.right)

            total_sum = left_sum + right_sum + node.val
            total_count = left_count + right_count + 1

            # Integer division performs floor rounding
            if node.val == total_sum // total_count:
                matching_nodes += 1

            return total_sum, total_count

        post_order(root)
        return matching_nodes