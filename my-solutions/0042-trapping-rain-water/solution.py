class Solution:
    def trap(self, height: List[int]) -> int:
        maxR = [float(-inf)] * len(height)
        maxL = [float(-inf)] * len(height)
        currMaxL, currMaxR = float(-inf),  float(-inf)
        water = 0
        for i in range(len(height)):
            currMaxL = max(currMaxL, height[i])
            maxL[i] = currMaxL

            currMaxR = max(currMaxR, height[len(height) - 1 - i])
            maxR[len(height) - 1 - i] = currMaxR

        for i in range(1, len(height) - 1):
            if maxR[i] > height[i] and maxL[i] > height[i]:
                water += min(maxR[i], maxL[i]) - height[i]

        return water
