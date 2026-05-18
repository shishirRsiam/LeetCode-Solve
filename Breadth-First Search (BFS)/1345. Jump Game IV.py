class Solution:
    def minJumps(self, nums: List[int]) -> int:
        n = len(nums)
        store = defaultdict(list)
        for i in range(n):
            store[nums[i]].append(i)
        
        dq = deque()
        dq.append([0, 0])
        
        visited = set()
        while dq:
            idx, count = dq.popleft()
            if idx == n - 1:
                return count

            if idx + 1 < n and (idx + 1) not in visited:
                visited.add(idx + 1)
                dq.append([idx + 1, count + 1])
            if idx - 1 >= 0 and (idx - 1) not in visited:
                visited.add(idx - 1)
                dq.append([idx - 1, count + 1])

            for i in store[nums[idx]]:
                if not i in visited and i != idx:
                    visited.add(i)
                    dq.append([i, count + 1])
            store[nums[idx]].clear()

        return -1