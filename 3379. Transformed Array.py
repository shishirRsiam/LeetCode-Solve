class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        for i in range(n):
            if not nums[i]:
                continue
            if nums[i] > 0:
                ok = (i + nums[i]) % n
            else:
                ok = i - abs(nums[i]) % n
            ans[i] = nums[ok]
        return ans