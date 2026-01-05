class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        negetive, positive = [], []
        for arr in matrix:
            for val in arr:
                if val > 0:
                    positive.append(val)
                else:
                    negetive.append(val)
        min_num = 0
        if len(negetive) % 2:
            min_num = max(max(negetive + [-10**5]), -min(positive + [10**5]))
        return sum(positive) + (sum(negetive) * - 1) + (min_num + min_num)