class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = deque()
        maxArea = float('-inf')
        size = len(heights)

        for i in range(len(heights)):
            if i == 0:
                stack.append([i, heights[i]])
                continue
            
            # print(stack)
            idx = i
            # print(heights[i], stack[-1][1])
            while(len(stack) > 0 and heights[i] < stack[-1][1]):
                idx, height = stack[-1][0], stack[-1][1]
                area = height * (i - idx)
                # print(idx, height, area, maxArea)
                maxArea = max(maxArea, area)
                # print(idx, height, area, maxArea)
                stack.pop()
                # print("")
            
            # print(stack)

            stack.append([idx, heights[i]])
            # print(stack)
            # print("")
            # print("")

        while(len(stack) > 0):
            idx, height = stack[-1][0], stack[-1][1]
            maxArea = max(maxArea, height * (size - idx))
            stack.pop()
        
        return maxArea

