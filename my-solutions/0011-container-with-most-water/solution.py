class Solution:
    def maxArea(self, height: List[int]) -> int:
        i, j = 0, len(height)-1
        max = -1
        while(i < j):
            curr_vol = (j - i) * min(height[i], height[j])
            if curr_vol > max:
                max = curr_vol
            if height[j] < height[i]:
                j -= 1
            else:
                i += 1
                    
        return max
        
