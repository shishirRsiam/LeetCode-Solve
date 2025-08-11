class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        count = Counter()
        i, j, ans, n = 0, 0, 0, len(fruits)
        while j < n:
            count[fruits[j]] += 1
            while len(count) > 2:
                count[fruits[i]] -= 1
                if not count[fruits[i]]:
                    count.pop(fruits[i])
                i += 1
            j += 1
            ans = max(ans, j - i)
        return ans