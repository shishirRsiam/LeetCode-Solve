class Solution:
    def maxBottlesDrunk(self, numBottles: int, numExchange: int) -> int:

        ans, empty_bottles = numBottles, numBottles
        while empty_bottles >= numExchange:

            new_bottles = 0
            while empty_bottles - numExchange >= 0:
                new_bottles += 1
                empty_bottles -= numExchange
                numExchange += 1

            ans += new_bottles
            empty_bottles += new_bottles     

        return ans