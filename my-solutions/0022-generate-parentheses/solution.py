from collections import deque

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        stack = deque()
        output = []
        def gen(openN, closeN):
            if openN == closeN == n:
                output.append("".join(stack))
                return
            if openN < n:
                stack.append('(')
                gen(openN + 1, closeN)
                stack.pop()
            if openN > closeN:
                stack.append(')')
                gen(openN, closeN + 1)
                stack.pop()

        gen(0, 0)

        return output


