class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        store = []
        n = len(nums)
        for i in range(n - k + 1):
            store.append(nums[i:i+k])

        one_count_store = [-1]
        for val in set(nums):
            count = 0
            for arr in store:
                count += val in arr

            if count == 1:
                one_count_store.append(val)

        return max(one_count_store)