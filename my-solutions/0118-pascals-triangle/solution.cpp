class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res({{1}});
        for(int r = 0; r < numRows - 1; ++r) {
            vector<int> nextRow{};
            vector<int>& currRow = *(res.end() - 1);
            nextRow.push_back(1);
            for(int i = 0; i < currRow.size() - 1; ++i) {
                nextRow.push_back(currRow[i] + currRow[i + 1]);
            }
            nextRow.push_back(1);
            res.push_back(nextRow);
        }
        return res;
    }
};
