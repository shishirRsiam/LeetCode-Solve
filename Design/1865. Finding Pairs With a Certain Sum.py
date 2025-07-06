class FindSumPairs:
    def __init__(self, nums1: List[int], nums2: List[int]):
        self.nums1 = nums1
        self.nums2 = nums2
        self.nums2_count = Counter(nums2)

    def add(self, index: int, val: int) -> None:
        self.nums2_count[self.nums2[index]] -= 1
        if self.nums2_count[self.nums2[index]] <= 0:
            self.nums2_count.pop(self.nums2[index])

        self.nums2[index] += val
        self.nums2_count[self.nums2[index]] += 1
        
    def count(self, tot: int) -> int:
        count = 0
        for val in self.nums1:
            count += self.nums2_count[tot - val]
        return count