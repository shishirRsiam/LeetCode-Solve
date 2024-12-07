class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        def canSplit(mid):
            operations = 0
            for val in nums:
                operations += (val - 1) // mid
                if operations > maxOperations:
                    return False
            return True

        left, right = 1, max(nums)
        ans = right

        while left <= right:
            mid = left + (right - left) // 2
            if canSplit(mid):
                ans = mid
                right = mid - 1
            else:
                left = mid + 1

        return ans