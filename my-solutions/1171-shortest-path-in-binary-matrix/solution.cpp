class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // bfs solution
        if(grid[0][0] == 1) return -1;
        int m = grid.size(), n = grid[0].size();
        if(m == 1 && n == 1) return grid[0][0] == 0;

        queue<pair<int, int>> q;
        q.push({0, 0});

        int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        grid[0][0] = 1;

        int pathLength = 1;

        while(!q.empty()) {
            ++pathLength;
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                auto [r, c] = q.front();
                q.pop();
                for(auto& dir: directions) {
                    int nr = dir[0] + r, nc = dir[1] + c;
                    if(nr >= 0 && nr < m && nc >=0 && nc < n && grid[nr][nc] == 0) {
                        if(nr == m - 1 && nc == n - 1) return pathLength;
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }

        }

        return -1;
    }
};
