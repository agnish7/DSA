import math

class Solution:
    def contains(self, dict1, dict2):
        res = True
        
        for key in dict1.keys():
            if key not in dict2:
                return False
            elif dict1[key] > dict2[key]:
                return False
            else:
                continue
        
        return res
        
    def minWindow(self, s: str, t: str) -> str:
        
        t_dict = {}
        
        for i in range(len(t)):
            if t[i] in t_dict:
                t_dict[t[i]] += 1
            else:
                t_dict[t[i]] = 1
        
        min_window = ""
        min_len = math.inf
        
#         for i in range(len(s)):
#             for j in range(i, len(s)):
#                 s_dict = {}
#                 for k in range(i, j+1):
#                     if s[k] in s_dict:
#                         s_dict[s[k]] += 1
#                     else:
#                         s_dict[s[k]] = 1
                        
#                 # print(i, j)
#                 # print(t_dict, s_dict)
#                 # print(self.contains(t_dict, s_dict), min_len,  j-i+1)
#                 # print(s[i:j+1])

#                 if self.contains(t_dict, s_dict) and min_len > j-i+1:
#                     min_window = s[i:j+1]
#                     min_len = j-i+1
                    
#                 # print(min_len,  j-i+1)
#                 # print(" ")
        
        s_dict = {}
        last = 0
        for i in range(len(s)):
            if s[i] in s_dict:
                s_dict[s[i]] += 1
            else:
                s_dict[s[i]] = 1
            
            while(self.contains(t_dict, s_dict) and last < len(s)):
                if s[last] in s_dict:
                    if s_dict[s[last]] > 1:
                        s_dict[s[last]] -= 1
                    else:
                        del s_dict[s[last]]
                last += 1
                
                if i - last < min_len:
                    min_len = i - last
                    min_window = s[last-1:i+1]
                
                # print(min_window, i, last)
            
            
            
            
        
        return min_window
                        
