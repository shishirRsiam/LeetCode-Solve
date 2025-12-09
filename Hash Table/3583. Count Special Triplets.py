class Solution:
    def specialTriplets(self, nums: List[int]) -> int:
        mod = 10 ** 9 + 7

        ans, n = 0, len(nums)
        left_count = Counter()
        right_count = Counter(nums)
        for i in range(n):
            right_count[nums[i]] -= 1

            target = nums[i] * 2
            ans += (left_count[target] * right_count[target]) % mod

            left_count[nums[i]] += 1

        return ans % mod