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
    int maxSum = INT_MIN;

    int maxGain(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        // Ignore paths with negative sums
        int leftGain = std::max(maxGain(node->left), 0);
        int rightGain = std::max(maxGain(node->right), 0);

        // Price of a path arching through the current node
        int currentPathSum = node->val + leftGain + rightGain;

        // Update global maximum
        maxSum = std::max(maxSum, currentPathSum);

        // Return max gain if continuing the path up to the parent
        return node->val + std::max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};