class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        store = defaultdict(list)
        n = len(nums)
        for i in range(n):
            store[nums[i]].append(i)
        
        ans = 10 ** 10
        for val in store:
            n = len(store[val])
            for idx in range(n - 2):
                i = store[val][idx]
                j = store[val][idx + 1]
                k = store[val][idx + 2]
                ans = min(ans, abs(i - j) + abs(j - k) + abs(k - i))
        return -1 if ans == 10 ** 10 else ans


class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        store = defaultdict(list)
        n = len(nums)
        for i in range(n):
            store[nums[i]].append(i)
        
        ans = 10 ** 10
        for val in store:
            n = len(store[val])
            for i in store[val]:
                for j in store[val]:
                    if j == i: continue
                    for k in store[val]:
                        if k == i or k == j: continue
                        ans = min(ans, abs(i - j) + abs(j - k) + abs(k - i))
        return -1 if ans == 10 ** 10 else ans