class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        idx = 0
        while(idx < len(intervals) and newInterval[0] > intervals[idx][0]):
            idx += 1
        
        intervals.insert(idx, newInterval)

        # print(intervals)

        res = []
        curr = intervals[0]
        for i in range(1, len(intervals)):
            if intervals[i][0] <= curr[1]: # overlap
                curr[0] = min(intervals[i][0], curr[0])
                curr[1] = max(intervals[i][1], curr[1])
            else:
                # no overlap
                res.append(curr)
                curr = intervals[i]
        res.append(curr)
        # print(res)
        return res
