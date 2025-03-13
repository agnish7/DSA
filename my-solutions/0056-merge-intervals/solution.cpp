class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        intervals.push_back(vector<int>{INT_MAX, INT_MIN});
        vector<vector<int>> res;
        int j = 0, maxR = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0] > maxR) {
                res.push_back(vector<int>{intervals[j][0], maxR});
                j = i;
            }
            maxR = max(maxR, intervals[i][1]);
        }
        return res;
    }
};
