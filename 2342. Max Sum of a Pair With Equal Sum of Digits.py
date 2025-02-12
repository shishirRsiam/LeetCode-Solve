class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        ans, n = -1, len(nums)
        store = defaultdict(list)
        for i in range(n):
            digitSum = sum(int(digit) for digit in str(nums[i]))
            store[digitSum].append(nums[i])

        for key, value in store.items():
            if len(value) == 1: continue

            maxValue = max(value)
            if value.count(maxValue) > 1:
                ans = max(ans, maxValue + maxValue)
                continue

            secondMaxValue = -1
            for val in value:
                if val == maxValue: continue
                secondMaxValue = max(secondMaxValue, val)
            ans = max(ans, maxValue + secondMaxValue)
        return ans