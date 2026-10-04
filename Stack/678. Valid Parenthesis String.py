class Solution:
    def checkValidString(self, s: str) -> bool:
        star, stack = [], []
        for i, ch in enumerate(s):
            if ch == ')':
                if not stack:
                    if star: star = star[1:]
                    else: return False
                else: stack.pop()
            elif ch == '*': star.append(i)
            else: stack.append(i)

        while stack:
            last = stack.pop()
            if not star or last > star.pop():
                return False
        return True