class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        ans = ListNode(0)
        tail = ans
        blocked_nums = set(nums)
        while head:
            if head.val not in blocked_nums:
                tail.next = ListNode(head.val)
                tail = tail.next
            head = head.next
        return ans.next