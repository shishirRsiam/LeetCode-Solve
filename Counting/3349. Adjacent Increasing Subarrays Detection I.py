class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        store = []
        nums.append(-1005)
        count, n = 1, len(nums)
        for i in range(1, n):
            if nums[i - 1] < nums[i]:
                count += 1
            else:
                store.append(count)
                count = 1
        
        _2x = k + k
        n = len(store)
        for i in range(1, n):
            if store[i - 1] >= k and store[i] >= k:
                return True

        for x in store:
            if x >= _2x:
                return True
        return False