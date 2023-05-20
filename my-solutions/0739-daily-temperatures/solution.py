from collections import deque

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = deque()
        stack.append([temperatures[0], 0])
        res = [0] * len(temperatures)

        TEMP = 0
        IDX = 1

        for i, e in enumerate(temperatures):
            while len(stack) > 0 and e > stack[-1][TEMP]:
                res[stack[-1][IDX]] = i - stack[-1][IDX]
                stack.pop()
            else:
                stack.append([e, i])

        return res


