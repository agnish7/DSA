class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """

        def getKey(s):
            return "".join(sorted(s))

        res = []
        str_map = {}
        for i in range(len(strs)):
            key = getKey(strs[i])
            if key in str_map:
                str_map[key].append(strs[i])
            else:
                str_map[key] = [strs[i]]

        # print(str_map)

        
        for key in str_map:
            res.append(str_map[key])

        return res


