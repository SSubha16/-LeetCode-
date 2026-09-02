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
    public ListNode partition(ListNode head, int x) {
        // Dummy heads to anchor the start of the two partitions
        ListNode beforeHead = new ListNode(0);
        ListNode afterHead = new ListNode(0);

        // Iteration pointers for each partition
        ListNode before = beforeHead;
        ListNode after = afterHead;

        // Distribute nodes into the appropriate sublist
        while (head != null) {
            if (head.val < x) {
                before.next = head;
                before = before.next;
            } else {
                after.next = head;
                after = after.next;
            }
            head = head.next;
        }

        // Cut off the tail of the 'after' partition to prevent cycles
        after.next = null;

        // Splice the two partitions together
        before.next = afterHead.next;

        return beforeHead.next;
    }
}