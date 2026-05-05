class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not k or not head:
            return head

        n = 0
        copy = head
        while copy:
            n += 1
            copy = copy.next
        k %= n
        if not k:
            return head
        
        cur = head 
        for _ in range(n - k - 1):
            cur = cur.next
        new_head = cur.next
        cur.next = None

        new_tail = new_head
        while new_tail.next:
            new_tail = new_tail.next
        new_tail.next = head
        
        return new_head