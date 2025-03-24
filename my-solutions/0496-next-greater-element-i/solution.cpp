class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_greater;
        stack<int> stk;

        for(int i = nums2.size() - 1; i > -1; --i) {
            while(!stk.empty() && stk.top() < nums2[i]) stk.pop();
            if(stk.empty()) next_greater[nums2[i]] = -1;
            else next_greater[nums2[i]] = stk.top();
            stk.push(nums2[i]);
        }

        vector<int> res(nums1.size());
        for(int i = 0; i < nums1.size(); ++i) {
            res[i] = next_greater[nums1[i]];
        }

        return res;
    }
};
