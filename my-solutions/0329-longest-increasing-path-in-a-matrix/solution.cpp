class Solution {
    int cache[201][201] = {0};
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();

        int res = INT_MIN;
        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                res = max(res, dfs(r, c, matrix));
            }
        }
        return res;
    }
    int dfs(int r, int c, vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if(cache[r][c]) return cache[r][c];

        int res = 1;
        for(int i = 0; i < 4; ++i) {
            int x = r + dirs[i][0], y = c + dirs[i][1];
            if(x >=0 && x < m && y >=0 && y < n && matrix[r][c] < matrix[x][y])
            res = max(res, 1 + dfs(x, y, matrix));
        }

        return cache[r][c] = res;
    }
};
