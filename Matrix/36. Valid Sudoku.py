class Solution:
    def check3x3(self, board):
        directions = [
                (0, 0), (0, 3), (0, 6),
                (3, 0), (3, 3), (3, 6),
                (6, 0), (6, 3), (6, 6),
            ]
        for row, col in directions:
            seen = set()
            for i in range(row, row + 3):
                for j in range(col, col + 3):
                    s = board[i][j]
                    if s != '.' and s in seen:
                        return False
                    seen.add(s)
        return True

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            seen = set()
            for j in range(9):
                s = board[i][j]
                if s != '.' and s in seen:
                    return False
                seen.add(s)
        for i in range(9):
            seen = set()
            for j in range(9):
                s = board[j][i]
                if s != '.' and s in seen:
                    return False
                seen.add(s)
        return self.check3x3(board)