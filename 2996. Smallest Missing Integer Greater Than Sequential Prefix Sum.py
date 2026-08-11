class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        n = len(nums)

        idx, all_sum = 1, nums[0]
        while idx < n:
            if nums[idx] - 1 != nums[idx - 1]: break
            all_sum += nums[idx]
            idx += 1

        nums = set(nums)
        while all_sum in nums:
            all_sum += 1
        return all_sum