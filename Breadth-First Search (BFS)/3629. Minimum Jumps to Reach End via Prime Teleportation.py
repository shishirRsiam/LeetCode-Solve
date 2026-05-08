class Solution:
    def minJumps(self, nums: List[int]) -> int:
        primes = set()
        limit = max(nums)
        is_prime = [True] * (limit + 1)
        is_prime[0] = is_prime[1] = False
        for i in range(2, limit + 1):
            if not is_prime[i]: continue
            primes.add(i)
            for j in range(i * i, limit + 1, i):
                is_prime[j] = False

        n = len(nums)
        value_store = defaultdict(list)
        for i in range(n):
            value_store[nums[i]].append(i)

        visited = [False] * n
        visited[0] = True
        used_primes = set()
        
        que = deque([(0, 0)])
        while que:
            i, count = que.popleft()
            if i == n - 1: return count
                
            if i - 1 >= 0 and not visited[i - 1]:
                visited[i - 1] = True
                que.append((i - 1, count + 1))
            
            if i + 1 < n and not visited[i + 1]:
                visited[i + 1] = True
                que.append((i + 1, count + 1))
            
            if nums[i] in primes and nums[i] not in used_primes:
                used_primes.add(nums[i])
                for val2 in range(nums[i], limit + 1, nums[i]):
                    for j in value_store[val2]:
                        if not visited[j]:
                            visited[j] = True
                            que.append((j, count + 1))