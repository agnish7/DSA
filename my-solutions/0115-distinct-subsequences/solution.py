class Solution:
    def __init__(self):
        self.dict_sub_probs = {}
    def numDistinct(self, s: str, t: str) -> int:
        if len(s) >= 0 and len(t) == 0:
            return 1
        elif len(s) == 0:
            return 0
        else:
            i = 0;
            j = 0;
            if(s[i] == t[j]):
                #print(s[(j+1):], t[i], s[(j+1):], t[(i+1):])
                temp1 = 0
                temp2 = 0
                if (len(s[(j+1):]), len(t[i:])) not in self.dict_sub_probs:
                    temp1 = self.numDistinct(s[(j+1):], t[i:])
                    self.dict_sub_probs[(len(s[(j+1):]), len(t[i:]))] = temp1
                else:
                    temp1 = self.dict_sub_probs[(len(s[(j+1):]), len(t[i:]))]
                    
                if (s[(j+1):], t[(i+1):]) not in self.dict_sub_probs:
                    temp2 = self.numDistinct(s[(j+1):], t[(i+1):])
                    self.dict_sub_probs[(len(s[(j+1):]), len(t[(i+1):]))] = temp2
                else:
                    temp2 = self.dict_sub_probs[(len(s[(j+1):]), len(t[(i+1):]))]
                    
                return temp1 + temp2
            else:
                #print(s[(j+1):], t[i])
                return self.numDistinct(s[(j+1):], t[i:])
