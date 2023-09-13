class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
      if len(s1) > len(s2):
        return False
      s1_count = [0] * 26
      s2_count = [0] * 26

      for i in range(len(s1)):
        idx = ord(s1[i]) - ord('a')
        s1_count[idx] += 1
        idx = ord(s2[i]) - ord('a')
        s2_count[idx] += 1
      
      matchings = sum(map(lambda i: s1_count[i] == s2_count[i], range(26)))

      print(matchings, s1_count, s2_count)

      for i in range(len(s1), len(s2)):
        if matchings == 26:
          return True

        idx_l = ord(s2[i - len(s1)]) - ord('a')
        s2_count[idx_l] -= 1
        if s2_count[idx_l] == s1_count[idx_l]:
          matchings += 1
        elif s2_count[idx_l] == s1_count[idx_l] - 1: # this is so that we dont decrement matchings when there was already a mismatch and the s2_count just went down further by 1
          matchings -= 1
        
        idx_r = ord(s2[i]) - ord('a')
        s2_count[idx_r] += 1
        if s2_count[idx_r] == s1_count[idx_r]:
          matchings += 1
        elif s2_count[idx_r] == s1_count[idx_r] + 1:
          matchings -= 1
        
      return matchings == 26


