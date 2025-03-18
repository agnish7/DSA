class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size() - 2; ++i) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r]; // Store sum for clarity and efficiency
                if(sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    while(l < r && nums[l] == nums[l - 1]) ++l;
                    --r;
                    while(l < r && nums[r] == nums[r + 1]) --r;
                }
                else if(sum > 0) --r;
                else ++l;
            }
        }
        return res;
    }
};
