class Solution:
    def judgeCircle(self, moves: str) -> bool:
        start = 0
        for move in moves:
            if move == 'U':
                start += 1
            elif move == 'D':
                start -= 1
            
            if move == 'L':
                start -= 100
            elif move == 'R':
                start += 100
        return start == 0