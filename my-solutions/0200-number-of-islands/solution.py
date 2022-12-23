class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        cache = set()
        def dfs(i, j):
            if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]):
                return
            if (i, j) in cache:
                return
            if grid[i][j] == "0":
                return
            if grid[i][j] == "1":
                cache.add((i, j))
                dfs(i + 1, j)
                dfs(i, j + 1)
                dfs(i - 1, j)
                dfs(i, j - 1)
        
        islands = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if (i, j) in cache or grid[i][j] == "0":
                    continue
                else:
                    if grid[i][j] == "1":
                        dfs(i, j)
                        islands = islands + 1

        return islands
