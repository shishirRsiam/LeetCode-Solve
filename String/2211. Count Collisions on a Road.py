class Solution:
    def countCollisions(self, directions: str) -> int:
        ans = 0
        n = len(directions)
        directions = [ch for ch in directions]
        for i in range(n - 1):
            if directions[i] + directions[i + 1] == "RL":
                ans += 2
                directions[i], directions[i + 1] = "S", "S"

        first_break, last_break = n, -1
        for i in range(n):
            if directions[i] == 'S':
                first_break = i
                break
                
        for i in range(n - 1, -1, -1):
            if directions[i] == 'S':
                last_break = i
                break

        for i in range(n):
            if directions[i] == 'L':
                ans += first_break < i
            elif directions[i] == 'R':
                ans += i < last_break
        return ans