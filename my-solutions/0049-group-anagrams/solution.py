class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dict_map = {}
        result = []
        for i in range(len(strs)):
            key = self.getKey(strs[i])
            if key not in dict_map:
                dict_map[key] = [strs[i]]
            else:
                dict_map[key].append(strs[i])
                
        for anagrams in dict_map.values():
            result.append(anagrams)
        
        return result
    
    def getKey(self, s):
        key = 0
        s = list(s)
        for i in range(len(s)):
            key += 10 ** int(ord(s[i]) - ord('a'))
        return key
            
