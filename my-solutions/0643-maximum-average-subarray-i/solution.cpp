class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        double maxSum = INT_MIN;

        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if(i >= k) sum -= nums[i - k]; // Adjust window size to k
            if(i >= k - 1) maxSum = max(maxSum, sum); // Update only when window is size k
        }



        return maxSum / k;
    }
};
