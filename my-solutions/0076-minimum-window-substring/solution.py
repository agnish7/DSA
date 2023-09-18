class Solution:
    def minWindow(self, s: str, t: str) -> str:
        sCount, tCount = defaultdict(int), defaultdict(int)
        for c in t:
            tCount[c] += 1
        need = len(list(tCount.keys()))
        l, have = 0, 0
        minWindow, minL, minR = float('inf'), -1, -1
        for r in range(len(s)):
            sCount[s[r]] += 1
            if sCount[s[r]] == tCount[s[r]]:
                have += 1
            while(have == need):
                # update the min window and l, r indices
                if r - l < minWindow:
                    minWindow = r - l
                    minR = r
                    minL = l
                sCount[s[l]] -= 1
                if sCount[s[l]] == tCount[s[l]] - 1:
                    have -= 1
                l += 1


        return s[minL:minR+1] if minWindow < float('inf') else ""
            
