class Solution:
    def maxDepth(self, s: str) -> int:
        ans = 0
        stack = []
        for i in range(len(s)):
            if s[i] == ')':
                while stack[-1] != '(':
                    stack.pop()
                ans = max(ans, stack.count('('))
                stack.pop()
            else:
                stack.append(s[i])
        return ans