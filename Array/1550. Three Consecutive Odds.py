class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        n = len(arr)
        for i in range(2, n):
            if arr[i] % 2 and arr[i - 1] % 2 and arr[i - 2] % 2:
                return True
        return False
    
    
class Solution(object):
    def threeConsecutiveOdds(self, arr):
        n = len(arr)
        for i in range(n - 2):
            if arr[i] % 2 and arr[i + 1] % 2 and arr[i + 2] % 2:
                return True
        return False
        