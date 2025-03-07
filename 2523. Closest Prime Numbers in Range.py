class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        max_num = right
        store = defaultdict(bool)
        store[1] = True
        def sieveOfEratosthenes():
            for i in range(2, int(sqrt(max_num)) + 1):
                if not store[i]:
                    for j in range(i * i, max_num + 1, i):
                        store[j] = True
        sieveOfEratosthenes()

        primes = []
        for i in range(left, right + 1):
            if not store[i]: primes.append(i)

        max_dif = 1e6
        ans = [-1, -1]
        n = len(primes)
        for i in range(1, n):
            if primes[i] - primes[i - 1] < max_dif:
                ans = [primes[i - 1], primes[i]]
                max_dif = primes[i] - primes[i - 1]

        return ans