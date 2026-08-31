class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        nums = []
        while head:
            nums.append(head.val)
            head = head.next
        
        store = []
        n = len(nums)
        for i in range(1, n - 1):
            if nums[i] > nums[i - 1] and nums[i] > nums[i + 1]:
                store.append(i)
            if nums[i] < nums[i - 1] and nums[i] < nums[i + 1]:
                store.append(i)
        
        if len(store) < 2:
            return [-1, -1]
        store.append(store[0])

        dif_store = []
        for i in range(1, len(store)):
            dif_store.append(abs(store[i] - store[i - 1]))
        return [min(dif_store), max(dif_store)]