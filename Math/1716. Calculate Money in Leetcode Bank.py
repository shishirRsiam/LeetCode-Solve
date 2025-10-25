class Solution:
    def totalMoney(self, n: int) -> int:
        total_money, cur_day_money, past_monday_money = 0, 1, 1
        for day in range(1, n + 1):
            total_money += cur_day_money
            cur_day_money += 1
            if day % 7 == 0:
                past_monday_money += 1
                cur_day_money = past_monday_money
        return total_money