class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        capacity.sort()
        capacity.reverse()

        apple_sum = sum(apple)
        for i, cap in enumerate(capacity):
            apple_sum -= cap
            if apple_sum <= 0:
                return i + 1
        return -1