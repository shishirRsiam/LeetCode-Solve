class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        Heap = [-gift for gift in gifts]
        heapify(Heap)
        for _ in range(k):
            top = -heappop(Heap)
            heappush(Heap, -int(math.sqrt(top)))
        return -sum(Heap)