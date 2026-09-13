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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }

        // Step 1: Calculate the length and locate the tail node
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            ++length;
        }

        // Step 2: Form a circular linked list
        tail->next = head;

        // Step 3: Normalize k
        k = k % length;
        int steps_to_new_tail = length - k;

        // Step 4: Traverse to the new tail
        ListNode* new_tail = tail;
        while (steps_to_new_tail--) {
            new_tail = new_tail->next;
        }

        // Step 5: Break the ring and establish the new head
        ListNode* new_head = new_tail->next;
        new_tail->next = nullptr;

        return new_head;
    }
};