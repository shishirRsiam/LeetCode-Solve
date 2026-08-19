class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        store = defaultdict(set)
        for row, seat in reservedSeats:
            store[row].add(seat)
        
        accept = [(2, 3, 4, 5), (4, 5, 6, 7), (6, 7, 8, 9)]

        ans = (n - len(store)) * 2 
        for row in store:
            for a, b, c, d in accept:
                if a in store[row] or b in store[row] or c in store[row] or d in store[row]:
                    continue

                ans += 1
                store[row].add(a)
                store[row].add(b)
                store[row].add(c)
                store[row].add(d)
                
        return ans