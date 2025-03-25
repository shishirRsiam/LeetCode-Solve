class Solution:
    def checkValidCuts(self, n: int, rectangles: List[List[int]]) -> bool:
        def solve(interval):
            count, last_interval = 0, -1
            for start, end in interval:
                if start >= last_interval:
                    count += 1
                last_interval = max(last_interval, end)
            return count
            
        x_interval = [(rectangle[0], rectangle[2]) for rectangle in rectangles]
        y_interval = [(rectangle[1], rectangle[3]) for rectangle in rectangles]

        x_interval.sort()
        y_interval.sort()

        return max(solve(x_interval), solve(y_interval)) >= 3