class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ans = []
        def helper(s):
            d = int(s)
            if (low <= d) and (d <= high):
                ans.append(d)
            if d > high: return 

            for i in range(1, 10):
                if int(s[-1]) + 1 == i:
                    helper(s + str(i))
                    
        for i in range(1, 10):
            helper(str(i))

        return sorted(ans)