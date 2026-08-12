class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        ans = 0
        count = Counter()
        i, j, n = 0, 0, len(nums)

        while j < n:
            count[nums[j]] += 1

            while count[nums[j]] > k:
                count[nums[i]] -= 1
                i += 1

            ans = max(ans, j - i + 1)
            j += 1

        return ans