class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        res = [0] * len(temperatures)
        stack = deque()
        for i in range(len(temperatures)):
            if len(stack) == 0:
                stack.append(i)
                continue
            while(len(stack) > 0 and temperatures[i] > temperatures[stack[-1]]):
                res[stack[-1]] = i - stack[-1]
                stack.pop()
            stack.append(i)

        return res
