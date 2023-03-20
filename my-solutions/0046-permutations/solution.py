class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if nums == None:
            return [[]]
        elif len(nums) == 0:
            return [[]]

        res = []
        for i in range(len(nums)):
            nums[i]
            temp = nums[:i]
            temp2 = nums[i+1:]
            temp.extend(temp2)

            permutations = self.permute(temp)
            
            for j in range(len(permutations)):
                temp = [nums[i]]
                temp.extend(permutations[j])
                res.append(temp)

        return res

