class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        
        for i, a in enumerate(nums):
            # skip through all elements that are same from the left
            if i > 0 and a == nums[i-1]:
                continue
                
            l, r = i + 1, len(nums) - 1
            while(l < r):
                sum = nums[l] + nums[r] + a
                # print([nums[l], nums[r], nums[i]])
                if sum == 0:
                    res.append([nums[l], nums[r], nums[i]])
                    
                    l += 1
                    while nums[l] == nums[l-1] and l < r:
                        l += 1
                elif sum > 0:
                    r -= 1
                else:
                    l += 1
        
        return res
