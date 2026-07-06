class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))

        ans = len(intervals) + 1
        ax, ay = intervals[0][0], intervals[0][1]

        for x, y in intervals:
            if x >= ax and y <= ay:
                ans -= 1
            ax = min(ax, x)
            ay = max(ay, y)
            
        return ans

    

class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))

        ans = 1
        ax, ay = intervals[0][0], intervals[0][1]

        for x, y in intervals:
            if x >= ax and y <= ay:
                continue
            ans += 1
            ax = min(ax, x)
            ay = max(ay, y)
            
        return ans