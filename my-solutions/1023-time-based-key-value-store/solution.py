class TimeMap:

    def __init__(self):
        self.timeMap = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key in self.timeMap.keys():
            self.timeMap[key].append((value, timestamp))
        else:
            self.timeMap[key] = [(value, timestamp)]

        
    def get(self, key: str, timestamp: int) -> str:
        if key not in self.timeMap:
            return ""

        l, r = 0, len(self.timeMap[key]) - 1
        
        while(l <= r):
            mid = int((l + r)/2)
            if self.timeMap[key][mid][1] == timestamp:
                return self.timeMap[key][mid][0]
            elif self.timeMap[key][mid][1] > timestamp:
                r = mid - 1
            else:
                l = mid + 1
        
        return self.timeMap[key][r][0] if self.timeMap[key][r][1] <= timestamp else ""


        


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
