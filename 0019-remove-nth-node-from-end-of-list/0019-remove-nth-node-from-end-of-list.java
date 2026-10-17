/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0, head);
        ListNode fast = dummy;
        ListNode slow = dummy;

        // Advance fast by n + 1 steps
        for (int i = 0; i <= n; i++) {
            fast = fast.next;
        }

        // Move fast to the end, keeping the gap constant
        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }

        // Unlink the target node
        slow.next = slow.next.next;

        return dummy.next;
    }
}