class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        count = defaultdict(int)
        for val in nums:
            count[val % value] += 1

        max_mex = int(1e5 + 5)
        for i in range(max_mex):
            if not count[i % value]:
                return i
            count[i % value] -= 1