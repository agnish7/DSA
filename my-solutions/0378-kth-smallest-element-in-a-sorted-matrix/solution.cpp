class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n - 1][n - 1];
        while(l < r) {
            int mid = l + (r - l) / 2;
            int pos = count(matrix, mid);
            
            if(pos < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }

    int count(vector<vector<int>>& matrix, int& mid) {
        int n = matrix.size();
        int r = n -1, c = 0;
        int res = 0;

        while(r >= 0 && c < n) {
            if(matrix[r][c] <= mid) {
                res += r + 1;
                ++c;
            } else {
                --r;
            }
        }

        return res;
    }
};
