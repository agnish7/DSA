class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        hashmap = {}
        for i in range(len(s)):
            if s[i] in hashmap.keys():
                hashmap[s[i]] = hashmap[s[i]] + 1
            else:
                hashmap[s[i]] = 1
        
        for j in range(len(t)):
            if t[j] in hashmap.keys():
                hashmap[t[j]] = hashmap[t[j]] - 1
            else:
                return False

        
        for key in hashmap.keys():
            if hashmap[key] != 0:
                return False

        return True
                    
