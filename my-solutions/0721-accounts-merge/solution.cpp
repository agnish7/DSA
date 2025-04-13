class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        vector<int> parent(n);
        for(int i = 0; i < n; ++i) parent[i] = i;

        vector<int> rank(n, 0);

        // build map
        unordered_map<string, vector<int>> email_to_index;
        for(int i = 0; i < n; ++i) {
            for(int j = 1; j < accounts[i].size(); ++j) {
                email_to_index[accounts[i][j]].push_back(i);
            }
        }

        // union sets of accounts sharing emails
        for(auto& [email, indices]: email_to_index) {
            for(int i = 1; i < indices.size(); ++i) {
                unite(indices[0], indices[i], parent, rank);
            }
        }

        // map emails to root of set
        unordered_map<int, vector<string>> index_to_emails;
        for (const auto& [email, indices] : email_to_index) {
            int root = find(indices[0], parent);
            index_to_emails[root].push_back(email);
        }
        vector<vector<string>> res;

        for(auto& [index, emails]: index_to_emails) {
            vector<string> merged_account{accounts[index][0]};
            sort(emails.begin(), emails.end());
            merged_account.insert(merged_account.end(), emails.begin(), emails.end());
            res.push_back(merged_account);
        }

        return res;
    }

    // union find algrithm.

    int find(int i, vector<int>& parent) {
        if(i != parent[i]) {
            parent[i] = find(parent[i], parent);
        }
        return parent[i];
    }

    void unite(int i, int j, vector<int>& parent, vector<int>& rank) {
        int pi = find(i, parent);
        int pj = find(j, parent);

        if(pi != pj) {
            if(rank[pi] > rank[pj]) {
                parent[pj] = pi; 
            } else if (rank[pi] < rank[pj]) {
                parent[pi] = pj;
            } else {
                parent[pi] = pj;
                ++rank[pj];
            }
        }
    }
};
