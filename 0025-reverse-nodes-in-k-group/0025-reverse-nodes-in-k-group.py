from typing import Optional

class ListNode:
    def __init__(self, val: int = 0, next: Optional['ListNode'] = None):
        self.val = val
        self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or k <= 1:
            return head

        dummy = ListNode(0, head)
        group_prev = dummy

        while True:
            # Check if there are at least k nodes remaining
            kth = self._get_kth_node(group_prev, k)
            if not kth:
                break

            group_next = kth.next

            # Reverse the k nodes in-place
            prev, curr = group_next, group_prev.next
            while curr != group_next:
                temp = curr.next
                curr.next = prev
                prev = curr
                curr = temp

            # Re-wire pointers around the reversed segment
            new_group_end = group_prev.next
            group_prev.next = kth
            group_prev = new_group_end

        return dummy.next

    def _get_kth_node(self, curr: Optional[ListNode], k: int) -> Optional[ListNode]:
        while curr and k > 0:
            curr = curr.next
            k -= 1
        return curr