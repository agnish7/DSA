class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        forward = copy.deepcopy(nums)
        backward = copy.deepcopy(nums)
        for i in range(1, len(nums)):
            forward[i] *= forward[i-1]
            backward[len(backward) - 1 - i] *= backward[len(backward) - i]
        
        result = copy.deepcopy(nums)
        for i in range(1, len(result) - 1):
            result[i] = forward[i-1] * backward[i+1]
        
        result[0] = backward[1]
        result[-1] = forward[-2]
        
        return result
