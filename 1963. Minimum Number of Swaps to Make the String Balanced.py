class Solution:
    def minSwaps(self, s: str) -> int:
        count = 0
        stack = []
        for ch in s:
            if ch == '[':
                stack.append(ch)
            else:
                if stack:
                    stack.pop()
                else:
                    count += 1
        return ceil(count / 2)