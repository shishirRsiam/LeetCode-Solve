class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        store = defaultdict(list)
        for num in arr:
            store[num.bit_count()].append(num)

        ans = []
        for bit_count in range(15):
            ans += sorted(store[bit_count])
        return ans