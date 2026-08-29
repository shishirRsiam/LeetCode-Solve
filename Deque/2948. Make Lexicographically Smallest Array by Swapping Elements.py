class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        nums_cp = list(nums)
        nums.sort()

        n = len(nums)
        parent_pos = 0

        parent = defaultdict(int)
        store = defaultdict(deque)

        parent[nums[0]] = 0
        store[parent_pos].append(nums[0])
        
        for i in range(1, n):
            if nums[i] - nums[i - 1] > limit:
                parent_pos += 1
            store[parent_pos].append(nums[i])
            parent[nums[i]] = parent_pos
        
        for i in range(n):
            parent_pos = parent[nums_cp[i]]
            nums_cp[i] = store[parent_pos].popleft()

        return nums_cp