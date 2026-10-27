"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""


class Solution:

  def connect(self, root: "Optional[Node]") -> "Optional[Node]":
    if not root:
      return None

    leftmost = root

    # Loop down the tree level by level
    while leftmost.left:
      curr = leftmost
      while curr:
        # 1. Connect left child to right child
        curr.left.next = curr.right

        # 2. Connect right child to adjacent left child (across parents)
        if curr.next:
          curr.right.next = curr.next.left

        curr = curr.next

      leftmost = leftmost.left

    return root