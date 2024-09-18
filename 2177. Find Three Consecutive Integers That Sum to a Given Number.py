class Solution(object):
    def sumOfThree(self, num):
        if not num % 3:
            mod = num / 3
            return [mod - 1, mod, mod + 1]
        return []