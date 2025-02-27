class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_multiset<int> prefix;
        prefix.insert(0);
        int res = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if(prefix.count(sum - k)) {
                res += prefix.count(sum - k);
            }
            prefix.insert(sum);
        }
        return res;
    }
};
