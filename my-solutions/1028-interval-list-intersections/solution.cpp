class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int f = 0, s = 0;
        vector<vector<int>> res;
        while(f < firstList.size() && s < secondList.size()) {
            if(firstList[f][0] <= secondList[s][1] && firstList[f][1] >= secondList[s][0]) {
                res.push_back(vector<int>{max(firstList[f][0], secondList[s][0]), min(firstList[f][1], secondList[s][1])});
            }
            if(firstList[f][1] > secondList[s][1]) {
                ++s;
            } else {
                ++f;
            }
        }
        return res;
    }
};
