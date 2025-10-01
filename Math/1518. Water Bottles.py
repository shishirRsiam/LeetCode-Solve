class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        ans, empty_bottles = numBottles, numBottles
        while empty_bottles >= numExchange:
            new_bottles = int(empty_bottles / numExchange)
            ans += new_bottles
            empty_bottles = new_bottles + empty_bottles - (new_bottles * numExchange) 
        return ans