class Solution {
public:

    double dfs(unordered_map<string, vector<pair<string, double>>> &mp, string st, string en, set<string> &s) {
        if (mp.find(st) == mp.end() || mp.find(en) == mp.end()) return -1.0; 
        if (st == en) return 1.0; 
        s.insert(st);
        for (auto &it : mp[st]) {
            if (s.find(it.first) == s.end()) {
                double result = dfs(mp, it.first, en, s);
                if (result != -1.0) { 
                    return it.second * result;
                }
            }
        }
        return -1.0; 
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> mp;
        int n = equations.size();
        for(int i = 0; i < n; i++){
            mp[equations[i][0]].push_back({equations[i][1], values[i]});
            mp[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
        vector<double> ans;
        int q = queries.size();
        for(int i = 0; i < q; i++){
            if(mp.find(queries[i][0]) == mp.end() || mp.find(queries[i][1]) == mp.end()){
                ans.push_back(-1.0);
            }
            else if(queries[i][0] == queries[i][1]){
                ans.push_back(1.0);
            }
            else{
                set<string> st;
                double tmp = dfs(mp, queries[i][0], queries[i][1], st);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};