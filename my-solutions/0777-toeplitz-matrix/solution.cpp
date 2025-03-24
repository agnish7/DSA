class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int c = 0; c < n; ++c) {
            int r = 0, c_bar = c;
            int prev = matrix[r][c];
            while(c_bar < n && r < m) {
                if(prev != matrix[r][c_bar]) return false;
                prev = matrix[r][c_bar];
                ++c_bar;
                ++r;
            }
        }

        for(int r = 0; r < m; ++r) {
            int c = 0, r_bar = r;
            int prev = matrix[r_bar][c];
            while(r_bar < m & c < n) {
                if(prev != matrix[r_bar][c]) return false;
                prev = matrix[r_bar][c];
                ++r_bar;
                ++c;
            }
        }

        return true;
    }
};
