class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        store = [(nums[i], i) for i in range(n)]
        store.sort()

        index = set()
        for i in range(k):
            index.add(store[n - i - 1][1])

        ans = []
        for i in range(n):
            if len(ans) == k:
                break
            if i in index:
                ans.append(nums[i])
        return ans