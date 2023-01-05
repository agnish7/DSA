class Solution:
    def minWindow(self, s: str, t: str) -> str:
        countT, window = {}, {}
        for c in t:
            countT[c] = 1 + countT.get(c, 0)

        have, need = 0, len(countT)
        j = 0
        res, reslen = "", float("inf")
        for i in range(len(s)):
            window[s[i]] = 1 + window.get(s[i], 0)
            if s[i] in countT and countT[s[i]] == window[s[i]]:
                have += 1
        
            
            while have == need:
                # print(window)
                if i - j + 1 < reslen:
                    res = s[j : i+1]
                    # print(res)
                    reslen = i - j + 1
                window[s[j]] -= 1
                if s[j] in countT and countT[s[j]] > window[s[j]]:
                    have -= 1
                j += 1

        return res
