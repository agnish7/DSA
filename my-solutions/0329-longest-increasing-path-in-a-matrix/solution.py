class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        visited = set()
        max_path_rc = {}
        def dfs(r, c, prev_val):
            if r >= len(matrix) or c >= len(matrix[0]) or r < 0 or c < 0:
                return 0
            if prev_val >= matrix[r][c]:
                return 0
            if (r, c) in visited:
                return 0
            if (r, c) in max_path_rc:
                return max_path_rc[(r, c)]


            visited.add((r, c))
            res =  1 + max(
                dfs(r-1, c, matrix[r][c]),
                dfs(r+1, c, matrix[r][c]),
                dfs(r, c-1, matrix[r][c]),
                dfs(r, c+1, matrix[r][c])
            )
            visited.discard((r, c))
            max_path_rc[(r, c)] = res
            return res
        
        max_path = float("-inf")
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                visitied = set()
                max_path = max(max_path, dfs(i, j, -1))

        return max_path
