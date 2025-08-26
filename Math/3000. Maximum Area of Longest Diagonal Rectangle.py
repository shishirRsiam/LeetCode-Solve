class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        dimensions.sort()
        ans, maxSqrt = 0, 0.0
        for val1, val2 in dimensions:
            curSqrt = sqrt((val1 * val1) + (val2 * val2))
            if maxSqrt <= curSqrt:
                maxSqrt = curSqrt
                ans = val1 * val2
        return ans