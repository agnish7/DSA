class Solution:
    def maxArea(self, height: List[int]) -> int:
        maxWater, l, r = float('-inf'), 0, len(height) - 1
        while(l < r):
            maxWater = max(maxWater, min(height[l], height[r]) * (r - l))
            if height[l] > height[r]:
                r -= 1
            else:
                l += 1
        
        return maxWater
