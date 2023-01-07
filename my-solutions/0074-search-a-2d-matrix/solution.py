class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix) <= 0:
            return False
        if target < matrix[0][0]:
            return False
        if target > matrix[len(matrix) - 1][len(matrix[0]) - 1]:
            return False

        def binSearch(array, num):
            if len(array) <= 0:
                return -1
            mid = len(array) // 2
            if num == array[mid]:
                return mid
            elif num < array[mid]:
                res = binSearch(array[:mid], num)
                return res
            else:
                res = binSearch(array[mid+1:], num)
                return mid + 1 + res if res != -1 else -1
        
        def bSearchMin(array, num):
            # print(array)
            if len(array) <= 1:
                return -1
            mid = len(array) // 2
            if num in range(array[mid - 1], array[mid]):
                return mid
            elif num < array[mid -1]:
                return bSearchMin(array[:mid], num)
            else:
                res = bSearchMin(array[mid:], num)
                return mid + res if res != -1 else -1

        if len(matrix) == 1:
            return binSearch(matrix[:][0], target) != -1 or binSearch(matrix[:][0], target) != -1

        firstcol = [row[0] for row in matrix]
        row = bSearchMin(firstcol, target)

        return binSearch(matrix[:][row -1], target) != -1 or binSearch(matrix[:][row], target) != -1
