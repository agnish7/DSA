class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:

        def binSearch(row):
            l, r = 0, len(matrix[0]) - 1
            # print(matrix[row])
            while(l <= r):
                mid = int((l+r)/2)
                if matrix[row][mid] == target:
                    return mid
                elif matrix[row][mid] > target:
                    r = mid - 1
                else:
                    l = mid + 1
            return -1

        l, r = 0, len(matrix) - 1
        while(l <= r):
            mid = int((l + r) / 2)
            # print(l, mid, r)
            if target <= matrix[mid][-1] and target >= matrix[mid][0]:
                return binSearch(mid) != -1
            elif target > matrix[mid][-1]:
                l = mid + 1
            else:
                r = mid - 1
        
        return False
        
