class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        # function that finds cells where water could have flow from to atlantic/pacific sides
        pac, atl = set(), set()
        ROWS = len(heights)
        COLS = len(heights[0])

        def dfs(r, c, visit, prevHeight):
            if (
                (r, c) in visit or
                r < 0 or
                c < 0 or
                r >= len(heights) or
                c >= len(heights[0]) or 
                prevHeight > heights[r][c]
                ):
                return

            visit.add((r, c))
            dfs(r - 1, c, visit, heights[r][c])
            dfs(r, c - 1, visit, heights[r][c])
            dfs(r + 1, c, visit, heights[r][c])
            dfs(r, c + 1, visit, heights[r][c])

        for i in range(COLS):
            dfs(0, i, pac, heights[0][i])
            dfs(ROWS - 1, i, atl, heights[ROWS - 1][i])

        for i in range(ROWS):
            dfs(i, 0, pac, heights[i][0])
            dfs(i, COLS - 1, atl, heights[i][COLS - 1])

        res = []
        for i in range(len(heights)):
            for j in range(len(heights[0])):
                if (i, j) in atl and (i, j) in pac:
                    res.append([i, j])
        return res
        
