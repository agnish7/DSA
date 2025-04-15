class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> i, vector<int> j){
            return i[0] < j[0];
        });


        vector<vector<int>> res;
        int first = 0, last = 0;

        for(int i = 0; i < intervals.size(); ++i) {
            if(i == 0) {
                first = intervals[i][0];
                last = intervals[i][1];
                continue;
            }
            if(intervals[i][0] <= last) {
                last = max(last, intervals[i][1]);
            } else {
                res.push_back({first, last});
                first = intervals[i][0];
                last = intervals[i][1];
            }
        }

        res.push_back({first, last});

        return res;
    }
};
