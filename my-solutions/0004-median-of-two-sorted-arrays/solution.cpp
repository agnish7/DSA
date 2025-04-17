class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n) return findMedianSortedArrays(nums2, nums1);        
        int l = 0, r = m;
        while(l <= r) {
            int x = (l + r) / 2;
            int y = (m + n + 1) / 2 - x;

            int l1 = (x == 0) ? INT_MIN : nums1[x - 1];
            int r1 = (x == m) ? INT_MAX : nums1[x];
            int l2 = (y == 0) ? INT_MIN : nums2[y - 1];
            int r2 = (y == n) ? INT_MAX : nums2[y];

            if(l1 <= r2 && l2 <= r1) {
                if((m + n)%2) return max(l1, l2);
                return double(max(l1, l2) + min(r1, r2)) / 2;
            }
            if(l1 > r2) r = x - 1;
            else l = x + 1;
        }

        return 0.0;
    }
};
