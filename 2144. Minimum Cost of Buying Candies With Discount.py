class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        cost.sort(reverse=True)
        ans, n = 0, len(cost)
        while len(cost) > 2:
            ans += sum(cost[:2])
            cost = cost[3:]
        return ans + (sum(cost) if cost else 0)
    
class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        cost.sort(reverse=True)
        
        ans = 0
        i, n = 0, len(cost)
        while len(cost) > 2:
            buy = cost[:3]
            cost = cost[3:]
            ans += sum(buy[:2])
        return ans + (sum(cost) if cost else 0)