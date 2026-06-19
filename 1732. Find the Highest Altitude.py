class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        ans, all_sum = 0, 0
        for val in gain:
            all_sum += val
            ans = max(ans, all_sum)
        return ans