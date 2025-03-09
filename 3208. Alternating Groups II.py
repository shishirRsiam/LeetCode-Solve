class Solution(object):
    def numberOfAlternatingGroups(self, nums, k):
        n = len(nums)
        i, j, cnt, ans = 0, 0, 0, 0
        nums += nums

        while j < (n+k)-1:
            if nums[j] == nums[j+1]: i = j
            j += 1
            if j-i >= k: ans += 1

        return ans

class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        i, j = 0, 0
        max_alternative = 0
        ans, n = 0, len(colors)
        colors += colors

        while(j < n + k - 1):
            if j and colors[j] == colors[j - 1]:
                max_alternative = 0
            max_alternative += 1

            if j - i + 1 == k:
                i += 1
                ans += max_alternative >= k
            j += 1
        return ans