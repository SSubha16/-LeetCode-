class Solution:
    def buildTree(self, preorder: list[int], inorder: list[int]) -> Optional[TreeNode]:
        inorder_index_map = {val: idx for idx, val in enumerate(inorder)}
        preorder_idx = 0

        def helper(in_left: int, in_right: int) -> Optional[TreeNode]:
            nonlocal preorder_idx
            
            if in_left > in_right:
                return None

            root_val = preorder[preorder_idx]
            root = TreeNode(root_val)
            preorder_idx += 1

            mid = inorder_index_map[root_val]

            root.left = helper(in_left, mid - 1)
            root.right = helper(mid + 1, in_right)

            return root

        return helper(0, len(inorder) - 1)