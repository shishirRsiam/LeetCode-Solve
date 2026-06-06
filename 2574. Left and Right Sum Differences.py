class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        n = len(nums)
        leftSum, rightSum = [0] * n, [0] * n

        for i in range(1, n):
            leftSum[i] = leftSum[i - 1] + nums[i - 1]
        for i in range(n - 2, -1, -1):
            rightSum[i] = rightSum[i + 1] + nums[i + 1]
        
        ans = [0] * n
        for i in range(n):
            ans[i] = abs(leftSum[i] - rightSum[i])
        return ans

class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        n = len(nums)
        leftSum, rightSum = [0] * n, [0] * n
        for i in range(1, n):
            leftSum[i] = leftSum[i - 1] + nums[i - 1]
            rightSum[n - i - 1] = rightSum[n - i] + nums[n - i]
        
        ans = [0] * n
        for i in range(n):
            ans[i] = abs(leftSum[i] - rightSum[i])
        return ans