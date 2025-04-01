class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // Check if start or end is blocked
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;
        
        // If grid is 1x1 and start is clear
        if(m == 1 && n == 1 && grid[0][0] == 0) return 1;
        
        // Directions (8-directional)
        int dirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        
        // Use a proper queue for BFS
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        // Mark start as visited
        grid[0][0] = 1;
        
        int dist = 1;
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                
                for(auto& dir : dirs) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    
                    // Check if next position is valid and unvisited
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                        // If we've reached the end
                        if(nx == m-1 && ny == n-1) return dist + 1;
                        
                        // Mark as visited and add to queue
                        grid[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
            dist++;
        }
        
        return -1; // No path found
    }
};
