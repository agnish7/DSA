class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sum_to_indices{{0, 1}};
        int sum = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            count += sum_to_indices[sum - k];
            ++sum_to_indices[sum];
        }
        return count;
    }
};
