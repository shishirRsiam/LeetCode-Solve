class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        store = defaultdict(int)
        for i in range(n):
            for j in range(i + 1, n):
                store[nums[i] * nums[j]] += 1

        for i in range(n):
            for j in range(i + 1, n):
                ans += (store[nums[i] * nums[j]] - 1) * 4
        return ans