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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        while (head != nullptr) {
            // Check if head is the start of a duplicate sequence
            if (head->next != nullptr && head->val == head->next->val) {
                // Skip all nodes with the duplicate value
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
                // Link prev directly past the last duplicate node
                prev->next = head->next;
            } else {
                // Value is unique, advance prev
                prev = prev->next;
            }
            // Move to the next node to evaluate
            head = head->next;
        }

        return dummy.next;
    }
};