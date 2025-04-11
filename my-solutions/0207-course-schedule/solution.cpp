class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // dfs
        vector<int> visited(numCourses, 0);
        unordered_map<int, vector<int>> adj; // pre-req : course
        for(auto& pre: prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        bool res = true;

        for(int i = 0; i < numCourses; ++i) {
            res = res && dfs(i, adj, visited);
        }

        return res;
    }

    bool dfs(int course, unordered_map<int, vector<int>>& adj, vector<int>& visited) {
        visited[course] = 1;

        bool res = true;
        for(auto& neighbor: adj[course]) {
            if(visited[neighbor] == 1) return false;
            if(visited[neighbor] == 0) {
                res = res && dfs(neighbor, adj, visited);
            }
        }

        visited[course] = 2;
        return res;
    }
};
