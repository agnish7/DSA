class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        n = len(nums)
        def dfs(i):

            if i >= n:
                return

            for j in range(len(res)):
                res.append(res[j] + [nums[i]])

            dfs(i + 1)

        dfs(0)

        return res
