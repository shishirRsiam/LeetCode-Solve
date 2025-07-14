class Solution:
    def getDecimalValue(self, head: Optional[ListNode]) -> int:
        binary_str = ''
        while head:
            binary_str += '1' if head.val else '0'
            head = head.next
        return int(binary_str, 2)