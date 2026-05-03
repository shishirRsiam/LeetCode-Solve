class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        s += s
        return len(s) / 2 == len(goal) and goal in s

class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        return len(s) == len(goal) and s in goal + goal