class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n - 1][n - 1];

        while(l < r) {
            int m = l + (r - l) / 2;
            int pos = countSmaller(m, matrix);
            if(pos < k) l = m + 1;
            else r = m;
        }

        return l;
    }

    int countSmaller(int num, vector<vector<int>>& matrix) {
        int n = matrix.size();
        int r = n - 1, c = 0;

        int count = 0;
        while(r > -1 && c < n) {
            if(matrix[r][c] <= num) {
                count += r + 1;
                ++c;
            } else {
                --r;
            }
        }

        return count;
    }
};
