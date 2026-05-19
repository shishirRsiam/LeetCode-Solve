class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        nums1, nums2 = set(nums1), set(nums2)
        nums1 = list(nums1)
        nums1.sort()
        for num in nums1:
            if num in nums2: return num
        return -1