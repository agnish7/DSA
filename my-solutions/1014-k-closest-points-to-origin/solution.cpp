class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto dist = [](vector<int> a) {
            return a[0] * a[0]  + a[1] * a[1];
        };
        auto cmp = [dist](vector<int> a, vector<int> b){
            return dist(a) < dist(b);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> kClosest(cmp);
        vector<vector<int>> res;
        kClosest.push(points[0]);
        for(int i = 1; i < points.size(); ++i) {
            if(dist(points[i]) < dist(kClosest.top()) || kClosest.size() < k) kClosest.push(points[i]);
            if(kClosest.size() > k) kClosest.pop();
        }
        while(!kClosest.empty()) {
            res.push_back(kClosest.top());
            kClosest.pop();
        }
        return res;
    }
};
