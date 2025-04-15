class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainder_to_index;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int remainder = sum % k;

            if(remainder == 0 && i >= 1) return true;
            if(remainder_to_index.count(remainder) && remainder_to_index[remainder] < i - 1) return true;
            if(!remainder_to_index.count(remainder)) remainder_to_index[remainder] = i;
        }

        return false;
    }
};
