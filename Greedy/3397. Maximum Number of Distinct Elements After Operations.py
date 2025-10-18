class Solution:
    def maxDistinctElements(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        
        cur_min = nums[0] - k - 1
        for i in range(n):
            prev_range, next_range = nums[i] - k, nums[i] + k
            if cur_min < prev_range:
                cur_min = prev_range
            elif prev_range <= cur_min and cur_min < next_range:
                cur_min += 1
            nums[i] = cur_min

        return len(set(nums))