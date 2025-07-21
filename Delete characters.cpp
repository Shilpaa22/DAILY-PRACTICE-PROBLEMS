class Solution {
public:
    string makeFancyString(string s) {
        int n = (int)s.length();
        vector<vector<int>> C(n, vector<int>(26, 0));
        string A = "";
        for (int i = 0; i < n; ++i) {
            if (i > 0) C[i] = C[i - 1];
            C[i][s[i] - 'a']++;
            if (C[i][s[i] - 'a'] < 3) A.push_back(s[i]);
            if (i - 1 >= 0 && s[i] != s[i - 1]) C[i][s[i - 1] - 'a'] = 0;
        }
        return A;
    }
};