class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        A, B = nums1, nums2
        if len(A) > len(B):
            B, A = A, B

        l, r = 0, len(A) - 1
        size = len(nums1) + len(nums2)
        while(True):
            i = (l + r) // 2
            j = size // 2 - i - 2

            # print(l, r, i, j)

            Aleft = A[i] if i >= 0 else float('-inf')
            Aright =  A[i+1] if i + 1 < len(A) else float('inf')
            Bleft = B[j] if j >= 0 else float('-inf')
            Bright = B[j + 1] if j + 1 < len(B) else float('inf')

            
            # print(Aleft, Bleft, Aright, Bright)
            # print("")

            if Aleft <= Bright and Bleft <= Aright:
                if size % 2 == 0:
                    return (min(Aright, Bright) + max(Aleft, Bleft)) / 2
                else:
                    return min(Aright, Bright)

            elif Aleft > Bright:
                r = i - 1
            else:
                l = i + 1

            
