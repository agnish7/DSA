from queue import LifoQueue as stack

class Solution:
    def isValid(self, s: str) -> bool:
        stk = stack(maxsize=10000)
        for i in range(len(s)):
            if s[i] == '(' or s[i] == '{' or s[i] == '[':
                stk.put(s[i])
            elif s[i] == ')':
                if stk.empty():
                    return False
                top = stk.get()
                if top != '(':
                    return False
            elif s[i] == '}':
                if stk.empty():
                    return False
                top = stk.get()
                if top != '{':
                    return False
            elif s[i] == ']':
                if stk.empty():
                    return False
                top = stk.get()
                if top != '[':
                    return False
            else:
                return False
        
        if stk.empty():
            return True
        else:
            return False
                
                    
