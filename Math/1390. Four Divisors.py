class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        def divisor(num):
            store = set()
            i, sum = 1, 0
            while i * i <= num:
                if not num % i:
                    store.add(i)
                    store.add(num // i)
                i += 1
            if len(store) == 4:
                for div in store:
                    sum += div
            return sum
        
        ans = 0
        count = Counter(nums)
        for num in count:
            ans += divisor(num) * count[num]
        return ans