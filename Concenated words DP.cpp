class Solution {
public:
    vector<int> dp;

    int solve(string s, unordered_set<string>& st, int idx) {
        if (idx == s.size()) return 1;
        if (dp[idx] != -1) return dp[idx];
        string temp = ""; 
        int cnt = 0;
        for (int i = idx; i < s.size(); i++) {
            temp += s[i];
            if (st.find(temp) != st.end()) {
                cnt += solve(s, st, i + 1);
            }
        }
        return dp[idx] = cnt;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        vector<string> res;
        for (int i = 0; i < words.size(); i++) {
            dp.assign(words[i].size(), -1);
            if (solve(words[i], st, 0) > 1) {
                res.push_back(words[i]);
            }
        }
        return res;
    }
};