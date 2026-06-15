class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head.next:
            return None
            
        n = 0
        cp_head = head
        while cp_head:
            n += 1
            cp_head = cp_head.next

        i = 0
        cur = head
        target = n // 2
        while cur and cur.next:
            i += 1
            if i == target:
                cur.next = cur.next.next
                break
            cur = cur.next

        return head