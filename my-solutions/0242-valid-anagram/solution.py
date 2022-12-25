class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dict_s = {}
        for i in range(len(s)):
            if s[i] in dict_s:
                dict_s[s[i]] += 1
            else:
                dict_s[s[i]] = 1

        for i in range(len(t)):
            if t[i] not in dict_s:
                return False
            else:
                dict_s[t[i]] -= 1
                if dict_s[t[i]] < 0:
                    return False

        for key in dict_s:
            if dict_s[key] != 0:
                return False

        return True
