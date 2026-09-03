class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        MAX = 10 ** 10
        odd, even = MAX, MAX
        for val in nums1:
            if val % 2 == 0:
                even = min(even, val)
        
        for val in nums1:
            if val % 2:
                odd = min(odd, val)

        n = len(nums1)
        def make(flag):
            nums = nums1.copy()
            for i in range(n):
                if nums[i] % 2 != flag:
                    op1 = nums[i] - even
                    op2 = nums[i] - odd
                    if op1 > 0 and op1 % 2 == flag:
                        nums[i] = op1
                    elif op2 > 0 and op2 % 2 == flag:
                        nums[i] = op2
                    else:
                        return False
            return True

        return make(0) or make(1)

    