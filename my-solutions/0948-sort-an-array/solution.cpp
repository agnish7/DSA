class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    void quicksort(vector<int>& nums, int l, int r) {
        if(l >= r) {
            return;
        }
        int i = l - 1;
        
        int pivot = l + std::rand() % (r - l + 1);

        swap(nums[r], nums[pivot]);

        for(int j = l; j < r; ++j) {
            if(nums[j] < nums[r]) {
                ++i;
                swap(nums[i], nums[j]);
            }
        }

        int p = i + 1;
        swap(nums[p], nums[r]);
        quicksort(nums, l, p - 1);
        quicksort(nums, p + 1, r);
    }
};
