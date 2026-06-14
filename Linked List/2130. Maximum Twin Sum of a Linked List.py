class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        n = 0
        cp_head = head
        while cp_head:
            n += 1
            cp_head = cp_head.next

        i = 0
        store = defaultdict(int)
        while head:
            key = i
            if i < (n // 2):
                key = n - i - 1
            store[key] += head.val
            i += 1
            head = head.next

        return max(store.values())