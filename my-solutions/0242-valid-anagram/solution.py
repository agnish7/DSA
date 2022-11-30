class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        char_map = {}

        for i in range(len(s)):
            if s[i] in char_map:
                char_map[s[i]] += 1
            else:
                char_map[s[i]] = 1

        print(char_map)

        for j in range(len(t)):
            if t[j] in char_map:
                char_map[t[j]] -=1
                if(char_map[t[j]] < 0):
                    # print('val less than zero')
                    return False
            else:
                # print('key not found')
                return False

        print(char_map)

        for k in char_map:
            if char_map[k] > 0:
                # print('val greater than 0')
                return False

        return True

