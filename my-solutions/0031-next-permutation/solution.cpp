class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        for(int i = n - 2; i > -1; --i) {
            if(nums[i] < nums[i + 1]) {
                int minGreater = INT_MAX;
                int minIdx = -1;
                for(int j = i + 1; j < n; ++j) {
                    if(nums[j] > nums[i] && nums[j] <= minGreater) {
                        minGreater = nums[j];
                        minIdx = j;
                    }
                }
                swap(nums[i], nums[minIdx]);
                reverse(nums.begin() + i + 1, nums.end());
                break;
            }

            if(i == 0) {
                reverse(nums.begin(), nums.end());
            }
        }
    }
};
