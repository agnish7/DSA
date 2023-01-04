import math
class Solution:
    def countBits(self, n: int) -> List[int]:
        if n == 0:
            return [0]
        pow2 = int(math.log(n, 2)) + 1
        res = [0, 1]
        while(pow2 > 1):
            temp = []
            for i in range(len(res)):
                temp.append(res[i] + 1)
            res.extend(temp)
            pow2 = pow2 - 1
        # print(res)
        return res[:n+1]
