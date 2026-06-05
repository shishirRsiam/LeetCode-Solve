class Solution:
    def digitFrequencyScore(self, n: int) -> int:
        return sum([int(val) * cnt for val, cnt in Counter(str(n)).items()])


class Solution:
    def digitFrequencyScore(self, n: int) -> int:
        ans = 0
        for val, cnt in Counter(str(n)).items():
            ans += int(val) * cnt
        return ans