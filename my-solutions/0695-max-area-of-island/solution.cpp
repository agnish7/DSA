class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int maxArea = 0;
        for(int r = 0; r < grid.size(); ++r) {
            for(int c = 0; c < grid[0].size(); ++c) {
                if(grid[r][c])
                maxArea = max(maxArea, dfs(grid, visited, r, c));
            }
        }
        return maxArea;
    }
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c) {
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) return 0;
        if(visited[r][c]) return 0;
        if(grid[r][c] == 0) return 0;
        visited[r][c] = true;
        return 1 + dfs(grid, visited, r + 1, c) + dfs(grid, visited, r - 1, c) + dfs(grid, visited, r, c - 1) + dfs(grid, visited, r, c + 1);
    }
};
