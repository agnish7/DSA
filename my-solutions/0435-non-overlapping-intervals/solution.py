import copy
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key = lambda a: (a[0], a[1]))


        def numErase(intervals):
            # print(intervals)
            if len(intervals) <= 1:
                return 0
            for i in range(1, len(intervals)):
                if intervals[i][0] < intervals[i-1][1]:
                    intervals.pop(i if intervals[i][1] > intervals[i-1][1] else i-1)
                    return 1 + numErase(intervals)
            return 0

        return numErase(intervals)

