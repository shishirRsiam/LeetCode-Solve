class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        ans = 0
        for op in operations:
            ans += '+' in op
            ans -= '-' in op
        return ans