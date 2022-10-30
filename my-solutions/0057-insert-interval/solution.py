class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:

        if len(intervals) == 0:
            return [newInterval]
        elif len(intervals) == 1:
            intervals.append(newInterval)
            intervals.sort(key=lambda a: a[0])
            if intervals[0][1] >= intervals[1][0]:
                intervals[0][1] = max(intervals[0][1], intervals[1][1])
                del intervals[1]
            return intervals

        l, r = 0, len(intervals)-1
        insert_pos = -1
        
        if intervals[l][0] > newInterval[0]:
            if newInterval[1] < intervals[0][0]:
                res = [newInterval]
                res.extend(intervals)
                return res
            insert_pos = 0
        elif intervals[r][0] < newInterval[0]:
            if intervals[r][1] >= newInterval[0]:
                intervals[r][1] = max(intervals[r][1], newInterval[1])
            else:
                intervals.append(newInterval)
            return intervals
        else:
            while(l <= r-1):
                mid = (l + r) // 2
                if intervals[mid][0] <= newInterval[0] <= intervals[mid+1][0]:
                    insert_pos = mid
                    break
                elif newInterval[0] < intervals[mid][0] and newInterval[0] < intervals[mid+1][0]:
                    r = mid
                elif newInterval[0] > intervals[mid][0] and newInterval[0] > intervals[mid+1][0]:
                    l = mid
                    
        # no overlap
        if newInterval[0] > intervals[insert_pos][1] and newInterval[1] < intervals[insert_pos+1][0]:
            res = intervals[:insert_pos+1]
            res.append(newInterval)
            res.extend(intervals[insert_pos+1:])
            return res

        # overlaps with prev interval
        if newInterval[0] <= intervals[insert_pos][1]:
            intervals[insert_pos][1] = max(intervals[insert_pos][1], newInterval[1])
            intervals[insert_pos][0] = min(intervals[insert_pos][0], newInterval[0])
            
        idx = insert_pos + 1
        # overlaps with next/next several interval/s
        if newInterval[1] >= intervals[insert_pos + 1][0]:
            while (idx < len(intervals) and intervals[idx][0] <= newInterval[1]):
                idx+=1
            idx -=1
            intervals[idx][0] = min(newInterval[0], intervals[idx][0])
            intervals[idx][1] = max(intervals[idx][1], newInterval[1])
        
        result = intervals[:insert_pos+1]
        result.extend(intervals[idx:])
        
        if result[insert_pos][1] >= result[insert_pos + 1][0]:
            result[insert_pos][1] = max(result[insert_pos][1], result[insert_pos + 1][1])
            del result[insert_pos + 1]
        
        

        return result
