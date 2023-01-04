class Solution:
    def trap(self, height: List[int]) -> int:
        water = 0
        l, r = 0, len(height) - 1
        maxL, maxR = height[l], height[r]
        while(l < r):
            if maxL < maxR:
                l += 1
                water += maxL - height[l] if maxL - height[l] > 0 else 0
                maxL = max(maxL, height[l])
            else:
                r -= 1
                water += maxR - height[r] if maxR - height[r] > 0 else 0
                maxR = max(maxR, height[r])
        
        return water
