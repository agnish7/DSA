class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """

        if target < min(candidates):
            return []

        res = []
        for i in range(len(candidates)):
            if candidates[i] == target:
                res.append([candidates[i]])
            elif candidates[i] < target:
                temp = self.combinationSum(candidates[i:], target - candidates[i])
                for j in range(len(temp)):
                    temp2 = [candidates[i]]
                    temp2.extend(temp[j])
                    res.append(temp2)
        
        return res
