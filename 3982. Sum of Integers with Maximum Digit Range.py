class Solution:
    def maxDigitRange(self, nums: list[int]) -> int:
        store = defaultdict(list)
        
        for val in nums:
            min_val, max_val = 10 ** 10, - 10 ** 10
            for ch in str(val):
                min_val = min(min_val, int(ch))
                max_val = max(max_val, int(ch))
            store[max_val - min_val].append(val)
        
        return sum(store[max(store)])