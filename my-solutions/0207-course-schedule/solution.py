class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj_list = {i: [] for i in range(numCourses)}
        for i in range(len(prerequisites)):
            adj_list[prerequisites[i][1]].append(prerequisites[i][0])
        
        # print(adj_list)

        visited = set()
        back_edge = False

        def dfs(node):
            if node in visited:
                # print(node, "back_edge")
                nonlocal back_edge 
                back_edge = True
                return
            else:
                visited.add(node)
                # print(node, neighbours)
                for nei in adj_list[node]:
                    dfs(nei)
                visited.discard(node)
                adj_list[node] = []

        for key in adj_list:
            back_edge = False
            dfs(key)
            # print(key, back_edge)
            if back_edge:
                return False
        
        # dfs(0)
        # if back_edge:
        #         return False

        return True
        

