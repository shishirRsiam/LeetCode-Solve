class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        ans = letters[0]
        i, j = 0, len(letters) - 1
        while i <= j:
            mid = i + (j - i) // 2
            if letters[mid] <= target:
                i = mid + 1
            else:
                ans = letters[mid]
                j = mid - 1 
        return ans
    