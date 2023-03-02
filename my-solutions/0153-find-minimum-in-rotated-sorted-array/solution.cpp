class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = size(nums) - 1 - 1;
        int rotate = -1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(nums[mid] > nums[mid + 1]) {
                rotate = mid;
                break;
            } else if(nums[mid] < nums[0]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }


        if(rotate == -1) {
            return nums[0];
        } else {
            return nums[rotate + 1];
        }
    }
};
