class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        count = Counter(nums)
        maxCount = max([count[val] for val in count])
        return sum([maxCount for val in count if maxCount == count[val]])



class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        maxCount = 0
        count = Counter(nums)
        for val in count:
            maxCount = max(maxCount, count[val])
        
        ans = 0
        for val in count:
            if count[val] == maxCount:
                ans += maxCount
        return ans