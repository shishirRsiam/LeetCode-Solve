class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        ans = ['']
        n = len(nums)
        nums = set(nums)
        def backtrack(cur):
            if ans[0]: return 
            if len(cur) == n:
                if cur not in nums:
                    ans[0] = cur
                return 
            backtrack(cur + '0')
            backtrack(cur + '1')
            
        backtrack('')
        return ans[0]