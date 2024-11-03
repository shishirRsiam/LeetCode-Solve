class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        s += s
        return len(s) / 2 == len(goal) and goal in s