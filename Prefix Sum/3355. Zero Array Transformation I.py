class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        n = len(nums)
        difArray = [0] * (n + 1)

        for l, r in queries:
            difArray[l] += 1
            difArray[r + 1] -= 1

        for i in range(1, n):
            difArray[i] += difArray[i - 1]
        
        for i in range(n):
            if nums[i] > difArray[i]:
                return False
        return True