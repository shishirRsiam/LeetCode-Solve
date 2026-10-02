class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        def is_valid(s):
            stack = []
            for ch in s:
                if ch == '(': stack.append(ch)
                else:
                    if not stack: return False
                    stack.pop()
            return not stack

        ans = []
        def backtrack(s):
            if len(s) == (n * 2):
                if is_valid(s): ans.append(s)
                return

            backtrack(s + '(')
            backtrack(s + ')')

        backtrack('')
        return ans