class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        minHeap = [(val, idx) for idx, val in enumerate(nums)]
        heapify(minHeap)

        for _ in range(k):
            val, idx = heappop(minHeap)
            heappush(minHeap, (val * multiplier, idx))
        
        ans = [0] * len(nums)
        while minHeap:
            val, idx = heappop(minHeap)
            ans[idx] = val
        return ans