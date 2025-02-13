class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        ans = 0
        arr = SortedList(nums)
        while len(arr) > 1 and k > arr[0]:
            ans += 1
            arr.add((arr[0] * 2) + arr[1])
            arr.discard(arr[1])
            arr.discard(arr[0])
        return ans