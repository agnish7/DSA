class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<double> small, large; // small: max heap, large: min heap
        vector<double> medians;
        
        for (int i = 0, j = 0; j < nums.size(); j++) {
            // Insert into appropriate set
            if (small.empty() || nums[j] <= *small.rbegin()) {
                small.insert(nums[j]);
            } else {
                large.insert(nums[j]);
            }
            
            // Balance sets: small can have at most one more element than large
            if (small.size() > large.size() + 1) {
                large.insert(*small.rbegin());
                small.erase(prev(small.end()));
            } else if (large.size() > small.size()) {
                small.insert(*large.begin());
                large.erase(large.begin());
            }
            
            // Compute median when window size is reached
            if (j - i + 1 == k) {
                medians.push_back(k % 2 ? *small.rbegin() : (*small.rbegin() + *large.begin()) / 2.0);
                
                // Remove element going out of window
                auto it = small.find(nums[i]);
                if (it != small.end()) {
                    small.erase(it);
                } else {
                    large.erase(large.find(nums[i]));
                }
                i++;
            }
        }
        
        return medians;
    }
};
