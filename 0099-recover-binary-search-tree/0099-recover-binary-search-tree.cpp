/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* node) {
        if (!node) return;

        inorder(node->left);

        // Detect inversion
        if (prev && prev->val > node->val) {
            if (!first) {
                first = prev; // First violation: select the larger node
            }
            second = node;    // Both violations: update to the smaller node
        }
        prev = node;

        inorder(node->right);
    }

public:
    void recoverTree(TreeNode* root) {
        inorder(root);

        // Swap the values back to restore BST properties
        if (first && second) {
            std::swap(first->val, second->val);
        }
    }
};