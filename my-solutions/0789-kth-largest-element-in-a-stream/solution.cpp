#include <queue>

using namespace std;

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> k_heap;
    int k;
public:
    KthLargest(int k, vector<int>& nums): k(k) {
        if(nums.empty()) {
            return;
        }
        // cout << "here1" << endl;
        for(int i = 0; i < size(nums); i++) {
            // cout << "here2" << endl;
            if(size(k_heap) < k) {
                // cout << "here3" << endl;
                k_heap.push(nums[i]);
            }
            else {
                // cout << "here4" << endl;
                if(nums[i] > k_heap.top()) {
                    // cout << "here5" << endl;
                    k_heap.pop();
                    // cout << "here6" << endl;
                    k_heap.push(nums[i]);
                    // cout << "here7" << endl;
                }
            }
        }
    }
    
    int add(int val) {
        if(size(k_heap) < k) {
            k_heap.push(val);
        } else {
            if(val > k_heap.top()) {
                // cout << "here8" << endl;
                k_heap.pop();
                // cout << "here9" << endl;
                k_heap.push(val);
                // cout << "here10" << endl;
            }
        }
        return k_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
