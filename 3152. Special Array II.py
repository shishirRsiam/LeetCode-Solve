class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        n = len(nums)
        store, ans = [], []

        for i in range(1, n):
            if (nums[i] % 2) == (nums[i - 1] % 2):
                store.append(i)

        for left, right in queries:
            idx = bisect_right(store, left)
            
            if idx < len(store) and store[idx] <= right: ans.append(False)
            else: ans.append(True)
        
        return ans