class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        minK, maxK = 1, max(piles)

        def numHours(k):
            return sum([int(math.ceil(x / k)) for x in piles])


        while(minK <= maxK):
            midK = int((minK + maxK) / 2)
            # print(minK, midK, maxK, numHours(midK))
            if numHours(midK) > h:
                minK = midK + 1
            else:
                maxK = midK - 1

        return minK
