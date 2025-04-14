class Solution {
public:
    int search(vector<int>& nums, int target) {
        // check nums[m] vs nums[l]
        // figure out which side of m is sorted (left or right)
        // move the l or r pointer depending on which side is sorted. We can only be sure of the side that is sorted.

        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(nums[m] == target) return m;

            if(nums[m] >= nums[l]) {
                if(nums[m] > target && target >= nums[l]) r = m - 1;
                else l = m + 1;
            } else {
                if(nums[m] < target && target <= nums[r]) l = m + 1;
                else r = m - 1;
            }
        }

        return -1;
    }
};
