class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        inRome = set()
        monthDay = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

        def walk(s, e):
            start_day, end_day = int(s[3:]), int(e[3:])
            start_month, end_month = int(s[:2]), int(e[:2])
            count = 0
            for cur_month in range(start_month, end_month + 1):
                for day in range(start_day, monthDay[cur_month] + 1):
                    key = f"{day}-{cur_month}"

                    count += key in inRome
                    inRome.add(key)
                    if day == end_day and cur_month == end_month:
                        break

                start_day = 1
            return count
            
        walk(arriveAlice, leaveAlice)
        return walk(arriveBob, leaveBob)