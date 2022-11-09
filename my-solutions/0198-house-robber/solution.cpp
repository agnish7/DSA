class Solution {
public:
    unordered_map<int, int> cache;
    int rob(vector<int>& nums) {
        if(size(nums) <= 0) {
            return 0;
        } else if(size(nums) == 1) {
            return nums[0];
        }
        if(cache.find(size(nums)) != cache.end()) {
            return cache[size(nums)];
        } else {
            vector<int> nminus1(nums.begin()+1, nums.end());
            vector<int> nminus2(nums.begin()+2, nums.end());
            cache[size(nums)] = max(nums[0] + rob(nminus2), rob(nminus1));
            return cache[size(nums)];
        }
    }
};
