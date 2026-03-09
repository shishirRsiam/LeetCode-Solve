class Solution:
    def minimumIndex(self, capacity: list[int], itemSize: int) -> int:
        store = [(capacity[i], i) for i in range(len(capacity))]
        store.sort()
        for cap, i in store:
            if cap >= itemSize:
                return i
        return -1