class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s2) < len(s1):
            return False
        dicts1 = {}
        dicts2 = {}

        for i in range(len(s1)):
            if s1[i] not in dicts1:
                dicts1[s1[i]] = 1
            else:
                dicts1[s1[i]] += 1

        # print(dicts1)
        
        sizes1 = len(s1)

        for i in range(sizes1):
            if s2[i] not in dicts2:
                dicts2[s2[i]] = 1
            else:
                dicts2[s2[i]] += 1
        
        # print(dicts2)
        
        for i in range(sizes1, len(s2)):
            if dicts2 == dicts1:
                return True
            
            if s2[i] not in dicts2:
                dicts2[s2[i]] = 1
            else:
                dicts2[s2[i]] += 1
            
            if dicts2[s2[i - sizes1]] == 1:
                del dicts2[s2[i - sizes1]]
            else:
                dicts2[s2[i - sizes1]] -= 1
        
        if dicts1 == dicts2:
            return True
        
        return False

