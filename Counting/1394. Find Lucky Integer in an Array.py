class Solution:
    def findLucky(self, arr: List[int]) -> int:
        ans = -1
        count = Counter(arr)
        for val in count:
            if val == count[val]:
                ans = max(ans, val)
        return ans