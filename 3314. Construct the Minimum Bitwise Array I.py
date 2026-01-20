class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        ans = []
        for num in nums:
            if num == 2:
                ans.append(-1)
                continue
            for i in range(1, num):
                if (i | (i + 1)) == num:
                    ans.append(i)
                    break
        return ans