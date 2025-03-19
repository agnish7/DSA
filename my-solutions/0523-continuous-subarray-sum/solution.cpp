class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cache({{0,-1}});
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if(k != 0) sum %= k;
            if(cache.count(sum) && i - cache[sum] >= 2) return true;
            if(!cache.count(sum)) cache[sum] = i;
        }
        return false;
    }
};
