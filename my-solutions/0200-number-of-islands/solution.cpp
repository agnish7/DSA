class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i >= size(grid) || j >= size(grid[0]) || grid[i][j] == '0') {
            return;
        } else {
            if(grid[i][j] == '1') grid[i][j] = '0';
            bfs(grid, i+1, j);
            bfs(grid, i, j+1);
            bfs(grid, i-1, j);
            bfs(grid, i, j-1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < size(grid); i++) {
            for(int j = 0; j < size(grid[0]); j++) {
                if(grid[i][j] == '1')  {
                    count++;
                    bfs(grid, i, j);
                }
            }
        }
        return count;
    }
};
