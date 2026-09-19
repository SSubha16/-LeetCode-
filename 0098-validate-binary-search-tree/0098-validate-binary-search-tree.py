from typing import Optional


# Definition for a binary tree node.
class TreeNode:

  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:

  def isValidBST(self, root: Optional[TreeNode]) -> bool:
    def validate(node: Optional[TreeNode], low: float, high: float) -> bool:
      if not node:
        return True

      # Node value must be strictly within bounds
      if not (low < node.val < high):
        return False

      # Left subtree must be < node.val; Right subtree must be > node.val
      return validate(node.left, low, node.val) and validate(
          node.right, node.val, high
      )

    return validate(root, float("-inf"), float("inf"))