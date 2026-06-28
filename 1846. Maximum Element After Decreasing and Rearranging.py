class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        arr.sort()

        arr[0] = 1
        ans, n = 1, len(arr)
        for i in range(1, n):
            ans += ans < arr[i]
        return ans