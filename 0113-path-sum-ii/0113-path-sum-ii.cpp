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
public:
    std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::vector<std::vector<int>> result;
        std::vector<int> currentPath;
        dfs(root, targetSum, currentPath, result);
        return result;
    }

private:
    void dfs(TreeNode* node, int remainingSum, std::vector<int>& currentPath, std::vector<std::vector<int>>& result) {
        if (!node) {
            return;
        }

        // Include current node in path
        currentPath.push_back(node->val);

        // Check if it's a leaf node with the matching sum
        if (!node->left && !node->right && node->val == remainingSum) {
            result.push_back(currentPath);
        } else {
            // Traverse children with updated sum
            dfs(node->left, remainingSum - node->val, currentPath, result);
            dfs(node->right, remainingSum - node->val, currentPath, result);
        }

        // Backtrack
        currentPath.pop_back();
    }
};