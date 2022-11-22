class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        max = float(-inf)
        res = [-1] * len(arr)
        for i in range(len(arr) - 1, 0, -1):
            if arr[i] > max:
                max = arr[i]
            res[i-1] = max
        # print(res)
        return res
