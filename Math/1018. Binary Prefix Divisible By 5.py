class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        s = ""
        ans = []
        for ch in nums:
            s += str(ch)
            isDiv = True
            if int(s, 2) % 5:
                isDiv = not isDiv
            ans.append(isDiv)
        return ans