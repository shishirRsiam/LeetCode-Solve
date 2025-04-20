class Solution:
    def isIdealPermutation(self, nums: List[int]) -> bool:
        n = len(nums)

        local_inversion_count, global_inversion_count = 0, 0
        for i in range(n - 1):
            local_inversion_count += nums[i] > nums[i + 1]
        
        pbds = SortedList()
        for i in range(n):
            global_inversion_count += len(pbds) - pbds.bisect_left(nums[i])
            if global_inversion_count > local_inversion_count:
                return False
            pbds.add(nums[i])

        return local_inversion_count == global_inversion_count