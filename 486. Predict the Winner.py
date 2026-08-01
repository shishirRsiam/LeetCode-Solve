class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        def dfs(i, j):
            if i > j:
                return 0

            take_left = nums[i] - dfs(i + 1, j)
            take_right = nums[j] - dfs(i, j - 1)

            return max(take_left, take_right)
        return dfs(0, len(nums) - 1) >= 0