class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        uninue_numbers = len(set(nums))

        for k in range(uninue_numbers, n + 1):
            i, j = 0, 0
            count = defaultdict(int)
            while j < n:
                count[nums[j]] += 1
                if j - i + 1 == k:
                    ans += len(count) == uninue_numbers
                    count[nums[i]] -= 1
                    if not count[nums[i]]:
                        count.pop(nums[i])
                    i += 1
                j += 1
        return ans 