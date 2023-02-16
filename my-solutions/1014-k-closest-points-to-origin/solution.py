import heapq

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        def distance(point):
            return (point[0]**2 + point[1]**2)**0.5

        distance_point_map = {}
        minheap = []

        for i in range(len(points)):
            dist = distance(points[i])
            if dist in distance_point_map:
                distance_point_map[dist].append(points[i])
            else:
                distance_point_map[dist] = [points[i]]
            heapq.heappush(minheap, dist)

        res = []
        iter = k
        while iter > 0:
            while iter > 0 and len(distance_point_map[minheap[0]]) > 0:
                res.append(distance_point_map[minheap[0]].pop())
                iter -= 1
            heapq.heappop(minheap)
        
        return res
