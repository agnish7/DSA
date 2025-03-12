class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        vector<int> res;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(nums[mid] >= target) {
                r = mid - 1; 
            } else {
                l = mid + 1;
            }
        }
        int start = l;

        l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(nums[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        int end = l;

        return start == end ? vector<int>{-1, -1} : vector<int>{start, end - 1};
    }
};
