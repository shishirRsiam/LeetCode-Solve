class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        ans = 0
        count = Counter(costs)
        for cost in sorted(set(costs)):
            aval = min(count[cost] * cost, coins)
            coins -= aval
            ans += aval // cost
        return ans 