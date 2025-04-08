class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        count = defaultdict(int)
        ans, curIndex, n = 0, 0, len(nums)
        
        for val in nums:
            count[val] += 1
            while count[val] == 2:
                ans += 1
                if curIndex < n:
                    count[nums[curIndex]] -= 1
                if curIndex + 1 < n:
                    count[nums[curIndex + 1]] -= 1
                if curIndex + 2 < n:
                    count[nums[curIndex + 2]] -= 1
                curIndex += 3

        return ans