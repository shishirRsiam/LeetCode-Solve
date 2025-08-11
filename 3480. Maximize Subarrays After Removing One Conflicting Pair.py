class Solution:
    def maxSubarrays(self, n: int, conflictingPairs: List[List[int]]) -> int:
        storePair = defaultdict(list)
        for a, b in conflictingPairs:
            if b < a:
                a, b = b, a
            storePair[b].append(a)

        extra = [0] * (n + 1)
        ans, maxPoint, secondMaxPoint = 0, 0, 0
        for end in range(1, n + 1):
            for num in storePair[end]:
                if num >= maxPoint:
                    secondMaxPoint = maxPoint
                    maxPoint = num
                elif num > secondMaxPoint:
                    secondMaxPoint = num

            ans += end - maxPoint
            extra[maxPoint] += maxPoint - secondMaxPoint
        return ans + max(extra)