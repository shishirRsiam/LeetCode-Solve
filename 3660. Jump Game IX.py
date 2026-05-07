class Solution:
    def maxValue(self, nums: List[int]) -> List[int]:
        n = len(nums)
        rightMax, leftMin = [0] * n, [0] * n
        
        rightMax[0] = nums[0]
        leftMin[n - 1] = nums[n - 1]

        for i in range(1, n):
            rightMax[i] = max(nums[i], rightMax[i - 1])
        for i in range(n - 2, -1, -1):
            leftMin[i] = min(nums[i], leftMin[i + 1])

        ans = [0] * n
        ans[n - 1] = rightMax[n - 1]
        for i in range(n - 2, -1, -1):
            if rightMax[i] <= leftMin[i + 1]:
                ans[i] = rightMax[i]
            else: ans[i] = ans[i + 1]
        return ans