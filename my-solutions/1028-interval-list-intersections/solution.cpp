class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        
        for (auto& i : firstList) {
            // Find intervals in secondList where end point >= i[0] (potential start of intersection)
            auto start = lower_bound(secondList.begin(), secondList.end(), i[0], 
                [](const vector<int>& element, int value) {
                    return element[1] < value;
                });
            
            // Find intervals in secondList where start point <= i[1] (potential end of intersection)
            auto end = upper_bound(secondList.begin(), secondList.end(), i[1], 
                [](int value, const vector<int>& element) {
                    return value < element[0];
                });
            
            // Check all intervals in the range [start, end) for intersections
            for (auto j = start; j != end; ++j) {
                int intersectStart = max(i[0], (*j)[0]);
                int intersectEnd = min(i[1], (*j)[1]);
                res.push_back({intersectStart, intersectEnd});
            }
        }
        
        return res;
    }
};
