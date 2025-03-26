class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> cache(m, vector<int>(n, 0));
        int res = INT_MIN;
        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                res = max(res, dfs(r, c, -1, matrix, visited, cache));
            }
        }

        // for(auto& r: cache) {
        //     for(auto& e: r) {
        //         cout << e  << " ";
        //     }
        //     cout << endl;
        // }
        return res;
    }
    int dfs(int r, int c, int prev, vector<vector<int>>& matrix, vector<vector<bool>>& visited, vector<vector<int>>& cache) {
        int m = matrix.size(), n = matrix[0].size();
        if(r >= m || r < 0 || c >= n || c < 0) return 0;
        if(prev >= matrix[r][c]) return 0;
        if(cache[r][c]) return cache[r][c];
        if(visited[r][c]) return 0;


        prev = matrix[r][c];
        int res = INT_MIN;
        vector<vector<int>> dirs = {{r - 1, c}, {r + 1, c}, {r, c - 1}, {r, c + 1}};
        for(auto& dir: dirs) {
            visited[r][c] = true;
            res = max(res, dfs(dir[0], dir[1], prev, matrix, visited, cache));
            visited[r][c] = false;
        }

        cache[r][c] = res + 1;

        return res + 1;
    }
};
