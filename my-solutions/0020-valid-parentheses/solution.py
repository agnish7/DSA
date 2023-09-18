class Solution:
    def isValid(self, s: str) -> bool:

        bracketStack = deque()
        for c in s:
            if len(bracketStack) == 0 and c in [')', '}', ']']:
                return False
            if len(bracketStack) > 0 and c in [')', '}', ']']:
                top = bracketStack[-1]
                if top == '(' and c != ')' or top == '{' and c != '}' or top == '[' and c != ']':
                    return False
                else:
                    bracketStack.pop()
            else:
                bracketStack.append(c)
        
        return len(bracketStack) == 0
