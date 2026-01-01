class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        return [int(ch) for ch in str(int("".join(map(str, digits))) + 1)]