class Solution:
    def rotateTheBox(self, boxGrid: List[List[str]]) -> List[List[str]]:
        for row in boxGrid:
            n = len(row)
            ptr = n - 1
            for i in range(n - 1, -1, -1):
                if row[i] == '#':
                    row[ptr] = '#'
                    if i != ptr:
                        row[i] = '.'
                    ptr -= 1
                if row[i] == '*':
                    ptr = i - 1
        return list(list(r) for r in zip(*boxGrid[::-1]))