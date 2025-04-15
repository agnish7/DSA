class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;

        int distance = 1;
        int m = grid.size(), n = grid[0].size();

        if(m == 1 & n == 1) return grid[0][0] == 0;

        // bfs
        int directions[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1}, {0, 1},
            {1, -1}, {1, 0}, {1, 1}
        };

        queue<pair<int, int>> q;
        q.push({0, 0});

        while(!q.empty()) {
            int size = q.size();
            ++distance;
            for(int i = 0; i < size; ++i) {
                auto pos = q.front();
                q.pop();
                for(auto& dir: directions) {
                    int x = pos.first + dir[0], y = pos.second + dir[1];
                    if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0) {
                        if(x == m - 1 && y == n - 1) return distance;
                        grid[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
        }

        return -1;
    }
};
