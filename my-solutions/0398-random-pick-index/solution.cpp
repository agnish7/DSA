class Solution {
    unordered_map<int, vector<int>> numIdxMap;
public:
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) numIdxMap[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        int randIdx = rand() % numIdxMap[target].size();
        return numIdxMap[target][randIdx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
