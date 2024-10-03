class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        nums = sorted(set(arr))

        Rank = 1
        rank = defaultdict(int)
        for num in nums:
            rank[num] = Rank
            Rank += 1 
        return [rank[num] for num in arr]