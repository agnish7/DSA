class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res{{}};
        dfs(nums, 0, res);
        return res;
    }
    void dfs(vector<int>& nums, int i, vector<vector<int>>& res) {
        if(i == nums.size()) return;
        int size = res.size();
        for(int idx = 0; idx < size; ++idx) {
            vector<int> s = res[idx];
            s.push_back(nums[i]);
            res.push_back(s);
        }
        dfs(nums, i + 1, res);
    }
};
