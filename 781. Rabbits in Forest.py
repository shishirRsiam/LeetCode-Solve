class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        ans = 0
        count = defaultdict(int)
        for val in answers:
            if count[val] > val:
                count[val] = 0
            if not count[val]:
                ans += val + 1
            count[val] += 1
        return ans