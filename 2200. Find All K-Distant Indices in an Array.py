class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        ans = []
        last_index, n = 0, len(nums)
        for j in range(n):
            if nums[j] == key:
                start = max(last_index, j - k)
                end = min(j + k + 1, n)
                for i in range(start, end):
                    ans.append(i)
                last_index = end
        return ans