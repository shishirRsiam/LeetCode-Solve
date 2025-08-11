class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        prev, store = set(), set()
        for val in arr:
            cur = set()
            for num in prev:
                cur.add(num | val)
                store.add(num | val)
            cur.add(val)
            store.add(val)
            prev = cur
        return len(store)