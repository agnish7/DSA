from collections import deque
class Solution:
    def isValid(self, s: str) -> bool:
        stac = deque()
        for i in range(len(s)):
            if s[i] in ["(", "{", "["]:
                stac.append(s[i])
            else:
                if len(stac) == 0:
                    return False
                top = stac.pop()
                if top == "(" and s[i] != ")":
                    return False
                if top == "{" and s[i] != "}":
                    return False
                if top == "[" and s[i] != "]":
                    return False
        
        return len(stac) == 0

