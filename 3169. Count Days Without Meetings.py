class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        ans, last_meetings = 0, 0
        for start, end in meetings:
            if start > last_meetings:
                ans += start - last_meetings - 1
            last_meetings = max(last_meetings, end)

        return ans + (days - last_meetings)