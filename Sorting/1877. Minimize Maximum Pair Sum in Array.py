class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        return max([nums[i] + nums[len(nums) - i - 1] for i in range(len(nums) // 2)])

class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()

        ans = 2
        i, j, = 0, len(nums) - 1
        while i < j:
            ans = max(ans, nums[i] + nums[j])
            i += 1
            j -= 1
        return ans