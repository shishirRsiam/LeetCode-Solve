class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        ans, curSum = 0, 0
        banned = set(banned)
        for num in range(1, n + 1):
            if maxSum < curSum + num: break
            if num in banned: continue

            ans += 1
            curSum += num
        return ans