class MinStack:

    def __init__(self):
        self.mainStack = deque()
        self.minStack = deque()

    def push(self, val: int) -> None:
        if len(self.mainStack) == 0:
            self.minStack.append(val)
        else:
            self.minStack.append(min(self.minStack[-1], val))
        self.mainStack.append(val)

    def pop(self) -> None:
        if len(self.mainStack) > 0:
            self.mainStack.pop()
            self.minStack.pop()


    def top(self) -> int:
        return self.mainStack[-1]

    def getMin(self) -> int:
        return self.minStack[-1]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
