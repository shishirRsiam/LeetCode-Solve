class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        ans = 10 ** 10
        count = Counter(text)
        for ch in 'ban':
            ans = min(ans, count[ch])
        ans = min(ans, count['o'] // 2)
        ans = min(ans, count['l'] // 2)
        return ans