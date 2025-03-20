class Solution {
private:
    int maxCrossingSum(std::vector<int>& nums, int left, int mid, int right) {
        // Maximum sum ending at mid (left half suffix)
        int leftSum = nums[mid];
        int currSum = leftSum;
        for (int i = mid - 1; i >= left; i--) {
            currSum += nums[i];
            leftSum = std::max(leftSum, currSum);
        }

        // Maximum sum starting at mid + 1 (right half prefix)
        int rightSum = nums[mid + 1];
        currSum = rightSum;
        for (int i = mid + 2; i <= right; i++) {
            currSum += nums[i];
            rightSum = std::max(rightSum, currSum);
        }

        // Return the sum of the maximum suffix and prefix
        return leftSum + rightSum;
    }

    int maxSubArrayHelper(std::vector<int>& nums, int left, int right) {
        // Base case: single element
        if (left == right) {
            return nums[left];
        }

        // Divide
        int mid = left + (right - left) / 2;

        // Conquer: max subarray in left half, right half, or crossing
        int leftMax = maxSubArrayHelper(nums, left, mid);
        int rightMax = maxSubArrayHelper(nums, mid + 1, right);
        int crossMax = maxCrossingSum(nums, left, mid, right);

        // Combine: return the maximum of the three
        return std::max({leftMax, rightMax, crossMax});
    }

public:
    int maxSubArray(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        return maxSubArrayHelper(nums, 0, nums.size() - 1);
    }
};
