class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;

        while(l <= r) {
            int i = l, m = l, j = r;
            int p = l + rand() % (r - l + 1);
            int pivot = nums[p];
            while(m <= j) {
                if(nums[m] > pivot) {
                    swap(nums[m], nums[i]);
                    ++m;
                    ++i;
                } else if(nums[m] < pivot) {
                    swap(nums[m], nums[j]);
                    --j;
                } else {
                    ++m;
                }
            }

            if(k >= i + 1 && k <= j + 1) {
                return nums[i];
            } else if (k < i) {
                r = i - 1;
            } else if (k > j) {
                l = j + 1;
            }
        }

        return INT_MIN;
    }
};
