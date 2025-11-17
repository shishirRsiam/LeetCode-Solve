class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        prev = n
        for i in range(n):
            if nums[i]:
                prev = i
                break
                
        for i in range(prev + 1, n):
            if nums[i]:
                distance = i - prev 
                prev = i
                if distance <= k:
                    return False
        return True