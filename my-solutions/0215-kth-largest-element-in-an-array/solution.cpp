class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minheap;
        for(auto& i: nums) {
            if(minheap.empty()) {
                minheap.push(i);
                continue;
            }
            if(i > minheap.top() || minheap.size() <= k) {
                minheap.push(i);
            }
            if(minheap.size() > k) 
                minheap.pop();
        }
        return minheap.top();
    }
};
