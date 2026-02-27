class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        ans = [first]
        for val in encoded:
            ans.append(ans[-1] ^ val)
        return ans