class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        less_val, greater_val, equal_val = [], [], []

        for val in nums:
            if val == pivot: equal_val.append(val)
            elif val < pivot: less_val.append(val)
            else: greater_val.append(val)

        return less_val + equal_val + greater_val