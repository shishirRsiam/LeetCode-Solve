class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        ans = []
        nums.sort()
        n = len(nums)
        for i in range(0, n - 3 + 1, 3):
            arr = [nums[i], nums[i + 1], nums[i + 2]]
            if k < arr[-1] - arr[0]:
                return []
            ans.append(arr)
        return ans