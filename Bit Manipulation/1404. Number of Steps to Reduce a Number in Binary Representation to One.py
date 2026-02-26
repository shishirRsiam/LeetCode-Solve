class Solution:
    def numSteps(self, s: str) -> int:
        count, cur_number = 0, int(s, 2)
        while cur_number != 1:
            if cur_number % 2:
                cur_number += 1
            else:
                cur_number = cur_number // 2
            count += 1
        return count