class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        return derived.count(1) % 2 == 0