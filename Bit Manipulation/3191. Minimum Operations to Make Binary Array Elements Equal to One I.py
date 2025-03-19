class Solution:
    def minOperations(self, nums: List[int]) -> int:
        flag = True
        ans, n = 0, len(nums)
        for i in range (0, n):
            if not nums[i]:
                cnt = 0
                while i+cnt < n and cnt < 3:
                    nums[i+cnt] = 0 if nums[i+cnt] else 1
                    cnt += 1
                if cnt == 3:
                    ans += 1
                else:
                    flag = not flag
                    break
        return ans if flag else -1 
                