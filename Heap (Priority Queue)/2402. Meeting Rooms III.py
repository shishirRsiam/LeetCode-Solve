class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        available, used, count = [i for i in range(n)], [], [0] * n
        for start, end in meetings:
            while used and start >= used[0][0]:
                _, room = heappop(used)
                heappush(available, room)
            if not available:
                end_time, room = heappop(used)
                end = end_time + (end - start)
                heappush(available, room)
            room = heappop(available)
            heappush(used, (end, room))
            count[room] += 1
        return count.index(max(count))