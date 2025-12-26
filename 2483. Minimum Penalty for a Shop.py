class Solution:
    def bestClosingTime(self, customers: str) -> int:
        n = len(customers)
        min_index, count, min_count = 0, 0, 0
        for i in range(n):
            count += customers[i] == 'N'
            count -= customers[i] == 'Y'
            if count < min_count:
                min_count = count
                min_index = i + 1
        return min_index