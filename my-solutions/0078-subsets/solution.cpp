class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res{{}};
        for(auto& num: nums) {
            vector<vector<int>> newSets;
            for(auto& r: res) {
                vector<int> newSet(r.begin(), r.end());
                newSet.push_back(num);
                newSets.push_back(newSet);
            }
            res.insert(res.end(), newSets.begin(), newSets.end());
        }
        return res;
    }
};
