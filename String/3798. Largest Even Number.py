class Solution:
    def largestEven(self, s: str) -> str:
        arr = [ch for ch in s]
        while arr and ord(arr[-1]) % 2:
            arr.pop()
        return "".join(arr)