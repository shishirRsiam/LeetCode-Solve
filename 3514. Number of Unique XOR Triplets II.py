class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        nums = list(set(nums))

        n = len(nums)
        store = set([0])
        for i in range(n):
            for j in range(i + 1, n):
                store.add(nums[i] ^ nums[j])
        
        ans = set()
        for v1 in nums:
            for v2 in store:
                ans.add(v1 ^ v2)

        return len(ans)