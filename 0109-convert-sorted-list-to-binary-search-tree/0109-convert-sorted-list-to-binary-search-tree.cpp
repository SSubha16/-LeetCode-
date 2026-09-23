/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        int length = 0;
        ListNode* curr = head;
        while (curr) {
            length++;
            curr = curr->next;
        }
        
        return buildBST(head, 0, length - 1);
    }

private:
    TreeNode* buildBST(ListNode*& head, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = left + (right - left) / 2;

        // 1. Build the left subtree
        TreeNode* leftChild = buildBST(head, left, mid - 1);

        // 2. The current head node becomes the root
        TreeNode* root = new TreeNode(head->val);
        root->left = leftChild;

        // Move to the next linked list node
        head = head->next;

        // 3. Build the right subtree
        root->right = buildBST(head, mid + 1, right);

        return root;
    }
};