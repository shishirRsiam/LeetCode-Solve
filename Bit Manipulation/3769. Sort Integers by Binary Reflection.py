class Solution:
    def sortByReflection(self, nums: List[int]) -> List[int]:
        store = []
        for val in nums:
            bin_num = bin(val)[2:]
            bin_num = bin_num[::-1]
            store.append((int(bin_num, 2), val))
        store.sort()
        return [num for _, num in store]