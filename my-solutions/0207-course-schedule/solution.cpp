class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> courseMap;
        unordered_map<int, bool> cache{};
        for(auto& p: prerequisites) courseMap[p[0]].push_back(p[1]);

        for(auto& [course, prereqs]: courseMap) {
            if(!check(courseMap, course, {}, cache)) return false;
        }

        return true;
    }
    bool check(unordered_map<int, vector<int>>& courseMap, int course, unordered_set<int> visited, unordered_map<int, bool>& cache) {
        if(visited.count(course)) {
            cache[course] = false;
            return false;
        }

        if(cache.count(course)) return cache[course];
        if(!courseMap.count(course)) {
            cache[course] = true;
            return true;
        }

        visited.insert(course);

        bool res = true;
        for(auto& p: courseMap[course]) {
            res = res && check(courseMap, p, visited, cache);
        }

        visited.erase(course);

        cache[course] = res;
        return res;
    }
};
