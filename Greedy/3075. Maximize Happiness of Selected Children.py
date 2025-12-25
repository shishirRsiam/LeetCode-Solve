class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness.sort()
        happiness.reverse()

        ans, used = 0, 0
        for happy in happiness:
            if used == k or happy - used <= 0:
                break
            ans += happy - used
            happy += 1
            used += 1
        return ans