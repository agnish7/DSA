class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ones = 0, zeros = 0, twos = nums.size() - 1;

        while(ones <= twos) {
            if(nums[twos] == 2) {
                --twos;
                continue;
            }

            if(nums[ones] == 2) {
                swap(nums[ones], nums[twos]);
                --twos;
            } else if(nums[ones] == 0) {
                swap(nums[ones], nums[zeros]);
                ++zeros;
                ++ones;
            } else ++ones;
        }
    }
};
