class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        ans, i, n = 0, 0, len(colors)
        while i < n:
            j = i + 1
            time = [neededTime[i]]
            while j < n and colors[j] == colors[i]:
                time.append(neededTime[j])
                j += 1
            i = j
            ans += sum(time) - max(time)
        return ans