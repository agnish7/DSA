class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1_chars = [0] * 26
        s2_chars = [0] * 26
        l = 0

        for c in s1:
            s1_chars[ord(c) - ord('a')] += 1

        def check_subset(s1_chars, s2_chars):
            res = True
            for i in range(len(s1_chars)):
                res = res and (s1_chars[i] <= s2_chars[i])
            return res

        for r in range(len(s2)):

            s2_chars[ord(s2[r]) - ord('a')] += 1
            if(check_subset(s1_chars, s2_chars)):
                # print(l, r, check_subset(s1_chars, s2_chars))
                while(l <= r and check_subset(s1_chars, s2_chars)):
                    s2_chars[ord(s2[l]) - ord('a')] -= 1
                    l += 1
                # print(l, r, s1_chars, s2_chars)
                l -= 1
                s2_chars[ord(s2[l]) - ord('a')] += 1
                # print(l, r, s1_chars, s2_chars)
            
            if s1_chars == s2_chars:
                return True
        
        return False


