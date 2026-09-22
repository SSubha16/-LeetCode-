class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        inorder_index_map = {val: idx for idx, val in enumerate(inorder)}
        postorder_idx = len(postorder) - 1

        def helper(in_left: int, in_right: int) -> Optional[TreeNode]:
            nonlocal postorder_idx

            if in_left > in_right:
                return None

            # Pick the current root value from the end of postorder
            root_val = postorder[postorder_idx]
            root = TreeNode(root_val)
            postorder_idx -= 1

            mid = inorder_index_map[root_val]

            # Crucial: Build the right subtree before the left subtree
            root.right = helper(mid + 1, in_right)
            root.left = helper(in_left, mid - 1)

            return root

        return helper(0, len(inorder) - 1)