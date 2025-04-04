class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int r = 0, c = 0;

        int dirs[4][2] = {{-1, 1}, {1, -1}}; // 0 = up, 1 = down
        int i = 0;

        vector<int> res;

        while(res.size() < m * n) {
            while(res.size() < m * n && r > -1 && c < n) {
                res.push_back(mat[r][c]);
                r += dirs[i][0];
                c += dirs[i][1];
            }

            if(c == n) {r += 2; --c;}
            else if(r == -1) ++r;

            i = (i + 1) % 2;

            while(res.size() < m * n && r < m && c > -1) {
                res.push_back(mat[r][c]);
                r += dirs[i][0];
                c += dirs[i][1];
            }

            if(r == m) {c += 2; --r;}
            else if(c == -1) ++c;

            i = (i + 1) % 2;
        }

        return res; 
    }
};
