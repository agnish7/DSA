class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        // for(auto& num: nums) cout << num << " ";
        return nums[k - 1];
    }
};
