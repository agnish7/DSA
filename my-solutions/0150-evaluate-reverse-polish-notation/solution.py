from collections import deque
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = deque()
        for c in tokens:
            if c in "*+/-":
                r = int(stack.pop())
                l = int(stack.pop())
                res = 0
                if c == "*":
                    res = l * r
                elif c == "+":
                    res = l + r
                elif c == "/":
                    res = l / r
                elif c == "-":
                    res = l - r
                stack.append(res)
            else:
                stack.append(int(c))
        
        return int(stack[-1])
