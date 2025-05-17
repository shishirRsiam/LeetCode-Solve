class Solution:
    def sortColors(self, nums: List[int]) -> None:
        zeroCount, oneCount, twoCount = 0, 0, 0
        for val in nums:
            zeroCount += val == 0
            oneCount += val == 1
            twoCount += val == 2
        
        cur = 0
        for _ in range(zeroCount):
            nums[cur] = 0
            cur += 1
        for _ in range(oneCount):
            nums[cur] = 1
            cur += 1
        for _ in range(twoCount):
            nums[cur] = 2
            cur += 1