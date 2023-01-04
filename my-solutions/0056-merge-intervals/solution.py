class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key = lambda a: a[0])
        curr = intervals[0]
        res = []
        for i in range(len(intervals)):
            if intervals[i][0] <= curr[1]:
                curr[0] = min(intervals[i][0], curr[0])
                curr[1] = max(intervals[i][1], curr[1])
            else:
                res.append(curr)
                curr = intervals[i]
        
        res.append(curr)
        return res
