class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(t) > len(s):
            return ""
        sCount, tCount = defaultdict(int), defaultdict(int)
        for c in t:
            tCount[c] += 1
        
        l, l_min, r_min, min_window = 0, 0, 0, float('inf')
        def checkSubString(sCount, tCount):
            res = True
            for key in tCount:
                res = res and tCount[key] <= sCount[key]
            return res
        
        for r in range(len(s)):
            sCount[s[r]] += 1
            # print(s[l:r+1], sCount, tCount, checkSubString(sCount, tCount))
            if checkSubString(sCount, tCount):
                while(checkSubString(sCount, tCount)):
                    # print(s[l:r+1], sCount, tCount, checkSubString(sCount, tCount))
                    sCount[s[l]] -= 1
                    l += 1
                l -= 1
                sCount[s[l]] += 1
                if r - l < min_window:
                    min_window = r - l
                    r_min = r
                    l_min = l
        return s[l_min:r_min+1] if min_window < float('inf') else ""
