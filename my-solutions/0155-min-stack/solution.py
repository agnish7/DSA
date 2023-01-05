from collections import deque
class MinStack:

    def __init__(self):
        self.stack = deque()
        self.minstack = deque()
        

    def push(self, val: int) -> None:
        self.stack.append(val)
        self.minstack.append(min(val, self.minstack[-1]) if self.minstack else val)
        

    def pop(self) -> None:
        self.stack.pop()
        self.minstack.pop()
        

    def top(self) -> int:
        if self.stack:
            return self.stack[-1]
        

    def getMin(self) -> int:
        if self.minstack:
            return self.minstack[-1]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
