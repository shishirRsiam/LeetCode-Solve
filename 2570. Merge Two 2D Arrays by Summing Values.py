class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        store = defaultdict(int)
        for id, val in nums1:
            store[id] += val
        for id, val in nums2:
            store[id] += val

        ans = []
        for id, val in store.items():
            ans.append([id, val])
        ans.sort()
        return ans