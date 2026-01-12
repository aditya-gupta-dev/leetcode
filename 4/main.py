class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        nums1.extend(nums2)
        nums1.sort()

        if len(nums1) % 2 == 0: 
            return (nums1[int(len(nums1)/2)] + nums1[int(len(nums1)/2)-1]) / 2 
        else: 
            return nums1[int(len(nums1)/2)]

nums1, nums2 = [1,2], [3,4]

print(Solution().findMedianSortedArrays(nums1, nums2))