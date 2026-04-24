class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        store = defaultdict(int)
        for m in moves:
            store[m] += 1
        max_val, min_val = max(store['L'], store['R']), min(store['L'], store['R'])
        return (max_val + store['_'] - min_val)