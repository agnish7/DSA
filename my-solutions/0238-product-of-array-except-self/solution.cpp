class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int> lp(size(nums));
       vector<int> rp(size(nums));
       vector<int> answer(size(nums));

       lp[0] = nums[0];
       rp[size(nums) - 1] = nums[size(nums) - 1];

       for(int i = 1; i < size(nums); i++) {
           int j = size(nums) - 1 - i;
           lp[i] = lp[i-1] * nums[i];
           rp[j] = rp[j+1] * nums[j];
       }

       for(int i = 0; i < size(nums); i++) {
           if(i == 0) {
               answer[i] = rp[i+1];
           }  else if(i == size(nums) - 1) {
               answer[i] = lp[i-1];
           } else {
               answer[i] = lp[i-1] * rp[i+1];
           }
       }

       return answer;
    }
};
