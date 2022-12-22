import heapq

class MedianFinder(object):

    def __init__(self):
        self.minh = [] # has the largest 1/2 of the elements
        self.maxh = [] # has the smallest 1/2 of the elements
        

    def addNum(self, num):
        """
        :type num: int
        :rtype: None
        """

        if len(self.maxh) <= 0:
            heapq.heappush(self.maxh, -num)
        else:
            if num > -self.maxh[0]:
                heapq.heappush(self.minh, num)
            else:
                heapq.heappush(self.maxh, -num)

        # print(self.minh)
        # print(self.maxh)

        # rebalancing
        while(len(self.maxh) > len(self.minh) - 1):
            temp = -heapq.heappop(self.maxh)
            heapq.heappush(self.minh, temp)

        while(len(self.minh) > len(self.maxh)):
            temp = heapq.heappop(self.minh)
            heapq.heappush(self.maxh, -temp)
        
        # print(self.minh)
        # print(self.maxh)
        # print("")

        
        
    def findMedian(self):
        """
        :rtype: float
        """

        if len(self.minh) == len(self.maxh):
            return float(self.minh[0] - self.maxh[0]) / 2
        else:
            return -self.maxh[0]
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
