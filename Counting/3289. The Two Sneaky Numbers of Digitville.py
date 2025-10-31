class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        ans1, ans2 = -1, -1
        count = Counter(nums)
        for val in count:
            if count[val] == 2:
                if ans1 == -1:
                    ans1 = val
                elif ans2 == -1:
                    ans2 = val
                    break
        return [ans1, ans2]