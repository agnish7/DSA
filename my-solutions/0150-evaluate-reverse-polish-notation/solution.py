class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        evalStack = deque()
        def performOp(op1, op2, op):
            if op == "+":
                return op1 + op2
            elif op == "-":
                return op1 - op2
            elif op == "*":
                return op1 * op2
            else:
                # print(op1, op2, int(op1/op2))
                return int(op1/op2)
        for i in range(len(tokens)):
            if tokens[i] in ["+", "-", "*", "/"]:
                op1 = int(evalStack[-1])
                evalStack.pop()
                op2 = int(evalStack[-1])
                evalStack.pop()
                evalStack.append(performOp(op2, op1, tokens[i]))
            else:
                evalStack.append(int(tokens[i]))
            # print(evalStack)

        return evalStack[-1]

            
