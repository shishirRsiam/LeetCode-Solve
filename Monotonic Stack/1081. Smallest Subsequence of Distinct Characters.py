class Solution:
    def smallestSubsequence(self, s: str) -> str:
        stack = []
        last_idx = {char: i for i, char in enumerate(s)}

        for i, ch in enumerate(s):
            if ch in stack: continue

            while stack and stack[-1] > ch and last_idx[stack[-1]] > i:
                stack.pop()
            
            stack.append(ch)
        
        return ''.join(stack)