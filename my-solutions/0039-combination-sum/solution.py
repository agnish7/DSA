class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        
        def dfs(idx, total, curr_array):
            if total - target == 0:
                res.append(curr_array.copy())
            elif total - target > 0 or idx >= len(candidates):
                return
            else:
                curr_array.append(candidates[idx])
                dfs(idx, total + candidates[idx], curr_array)
                curr_array.pop()
                dfs(idx + 1, total, curr_array)
            
        dfs(0, 0, [])
        return res
