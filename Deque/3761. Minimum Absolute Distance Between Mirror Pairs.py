class Solution:
    def minMirrorPairDistance(self, nums: List[int]) -> int:
        n = len(nums)
        store = defaultdict(deque)
        for i in range(n):
            store[nums[i]].append(i)

        ans = 10 ** 10
        for i in range(n):
            if store[nums[i]] and store[nums[i]][0] == i:
                store[nums[i]].popleft()

            num = int(str(nums[i])[::-1]) # Reverse Nums
            while store[num] and i >= store[num][0]:
                store[num].popleft()
            if store[num]:
                ans = min(ans, abs(i - store[num][0]))
            
        return -1 if ans == 10 ** 10 else ans