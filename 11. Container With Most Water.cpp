class Solution:
    def maxArea(self, height: List[int]) -> int:
        ans, i, j = 0, 0, len(height) - 1
        while i <= j:
            min_value = min(height[i], height[j])
            ans = max(ans, min_value * (j - i))

            if height[i] > height[j]: j -= 1
            else: i += 1
        return ans