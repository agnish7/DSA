class Solution {
public:
    bool searchArray(vector<vector<int>>& matrix, int row, int target) {
        // cout << row << " " << target << endl;
        int l = 0, r = size(matrix[row]) - 1;
        // cout << l << " " << r << endl;
        while(l <= r) {
            int mid = (l + r) / 2;
            // cout << l << " " << mid << " " << r << endl;
            // cout << target << " " << matrix[row][mid] << endl;
            if(target == matrix[row][mid])
                return true;
            else if(target > matrix[row][mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(size(matrix) == 1 && size(matrix[0]) == 1)
            return matrix[0][0] == target;
        if (size(matrix) == 1)
            return searchArray(matrix, 0, target);
        int l = 1, r = size(matrix) - 1;
        while(l <= r) {
            int row = (l + r) / 2;
            if(target == matrix[row][0] || target == matrix[row-1][0])
                return true;
            else if(target > matrix[row-1][0] && target < matrix[row][0])
                return searchArray(matrix, row - 1, target);
            else if(target > matrix[row][0])
                l = row + 1;
            else
                r = row - 1;
        }

        return searchArray(matrix, size(matrix) - 1, target);
    }
};
