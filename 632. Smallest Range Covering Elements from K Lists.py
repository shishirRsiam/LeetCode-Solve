import heapq
from typing import List

class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        k = len(nums)
        min_heap = []
        left = right = nums[0][0]
        for i in range(k):
            left = min(left, nums[i][0])
            right = max(right, nums[i][0])
            heapq.heappush(min_heap, (nums[i][0], i, 0))

        ans = [left, right]
        while True:
            n, i, idx = heapq.heappop(min_heap)  # Get the smallest element
            idx += 1  # Move to the next index in the list

            if idx == len(nums[i]):
                return ans  # If any list is exhausted, return the result

            # Push the next element from the same list into the heap
            heapq.heappush(min_heap, (nums[i][idx], i, idx))

            # Update right to the max of the current range
            right = max(right, nums[i][idx])

            # Update left to be the smallest element in the heap
            left = min_heap[0][0]

            # Check if the current range is smaller than the best one so far
            if right - left < ans[1] - ans[0]:
                ans = [left, right]