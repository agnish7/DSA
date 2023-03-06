class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        unordered_map<int, vector<vector<int>>> dist_map;
        priority_queue<int> pq;
        vector<vector<int>> result;
        for(int i = 0; i < size(points); i++) {
            int distance = pow(points[i][0], 2) + pow(points[i][1], 2);
            pq.push(-distance);
            dist_map[-distance].push_back(points[i]);
        }

        while(!pq.empty()) {
            // cout << pq.top() << endl;
            vector<vector<int>> curr_points = dist_map[pq.top()];
            for(int i = 0; i < size(curr_points); i++) {
                result.push_back(curr_points[i]);
                k--;
                if(k == 0) return result;
            }
            pq.pop();
        }

        return vector<vector<int>>({{}});
    }
};
