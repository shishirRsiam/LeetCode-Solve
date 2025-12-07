class Solution:
    def countOdds(self, low: int, high: int) -> int:
        return ((high % 2) or (low % 2)) + ((high - low) // 2)


class Solution:
    def countOdds(self, low: int, high: int) -> int:
        count = (high - low) // 2
        count += (high % 2) or (low % 2)
        return count