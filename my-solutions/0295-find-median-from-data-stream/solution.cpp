class MedianFinder {
private:
    priority_queue<int> small; // max-heap for smaller half
    priority_queue<int, vector<int>, greater<int>> large; // min-heap for larger half

public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        // Push to the appropriate heap
        if (small.empty() || num < small.top()) {
            small.push(num);
        } else {
            large.push(num);
        }
        
        // Balance heaps: small can have at most one more element than large
        if (small.size() > large.size() + 1) {
            large.push(small.top());
            small.pop();
        } else if (large.size() > small.size()) {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if (small.size() > large.size()) {
            return small.top(); // Odd number of elements
        }
        return (small.top() + large.top()) / 2.0; // Even number of elements
    }
};
