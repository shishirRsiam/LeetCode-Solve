class Solution:
    def reverseParentheses(self, s: str) -> str:
        n = len(s)
        stack = []
        for i in range(n):
            if s[i] == ')':
                new_stack = []
                while stack and stack[-1] != '(':
                    new_stack.append(stack.pop())
                
                stack.pop() # remove last '('
                stack += new_stack
            else:
                stack.append(s[i])
                
        return ''.join(stack)

        