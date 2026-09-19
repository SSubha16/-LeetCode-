from typing import Optional


# Definition for a binary tree node.
class TreeNode:

  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:

  def recoverTree(self, root: Optional[TreeNode]) -> None:
    """Do not return anything, modify root in-place instead."""
    first = None
    second = None
    prev = None

    def inorder(node: Optional[TreeNode]):
      nonlocal first, second, prev
      if not node:
        return

      inorder(node.left)

      # An inversion occurs when prev node value >= current node value
      if prev and prev.val > node.val:
        if not first:
          first = prev
        second = node

      prev = node
      inorder(node.right)

    inorder(root)

    # Swap the values of the two identified nodes
    if first and second:
      first.val, second.val = second.val, first.val