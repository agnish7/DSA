class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ctr = 0, curr = -1;
        for(auto& num: nums) {
            if(ctr == 0) {
                ++ctr;
                curr = num;
            } else {
                if(num == curr) ++ctr;
                else --ctr;
            }

        }
        return curr;
    }
};
