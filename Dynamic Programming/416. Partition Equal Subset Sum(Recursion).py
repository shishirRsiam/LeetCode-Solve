class Solution(object):
    def canPartition(self, nums):
        allSum = sum(nums)
        if allSum % 2: 
            return False

        memo = {}
        n = len(nums)
        target = allSum / 2
        def solve(i, curSum):
            if curSum == target:
                return True
            if curSum > target or i == n:
                return False

            if (i, curSum) in memo:
                return memo[(i, curSum)]

            pic = solve(i + 1, curSum + nums[i])
            not_pic = solve(i + 1, curSum)
            memo[(i, curSum)] = pic or not_pic
            return memo[(i, curSum)]

        return solve(0, 0)