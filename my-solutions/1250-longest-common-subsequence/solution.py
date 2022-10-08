class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        aux = [0 for i in range(len(text1) + 1)]
        aux = [copy.deepcopy(aux) for i in range(len(text2) + 1)]
        
        for i in range(1, len(text2) + 1):
            for j in range(1, len(text1) + 1):
                if text1[j - 1] == text2[i - 1]:
                    aux[i][j] = aux[i-1][j-1] + 1
                else:
                    aux[i][j] = max(aux[i][j-1], aux[i-1][j])
        # print(aux)
        return aux[-1][-1]
