class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        stack = []
        amount = target
        n = len(nums)

        def dfs(i):
            nonlocal amount

            if amount == 0:
                res.append(stack.copy())
                return
            if i == n or amount < 0:
                return

            stack.append(nums[i])
            amount -= nums[i]
            dfs(i)
            amount += nums[i]
            stack.pop()
            dfs(i + 1)

        dfs(0)
        return res
