# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:

  def pathSum(
      self, root: Optional[TreeNode], targetSum: int
  ) -> list[list[int]]:
    result = []

    def dfs(node: Optional[TreeNode], remaining_sum: int, current_path: list[int]):
      if not node:
        return

      # Include current node in path
      current_path.append(node.val)

      # Check if it's a leaf node with the matching sum
      if not node.left and not node.right and node.val == remaining_sum:
        result.append(list(current_path))  # Store a copy of the current path
      else:
        # Traverse children with updated sum
        dfs(node.left, remaining_sum - node.val, current_path)
        dfs(node.right, remaining_sum - node.val, current_path)

      # Backtrack
      current_path.pop()

    dfs(root, targetSum, [])
    return result