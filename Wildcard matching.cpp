class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<bool> c(m + 1, false), prev(m + 1, false);
        prev[0] = true;
        for (int j = 1; j <= m; j++) {
            prev[j] = prev[j - 1] && (p[j - 1] == '*');
        }
         prev[0] = true;

        for (int i = 1; i < n + 1; i++) {
                
            for (int j = 1; j < m + 1; j++) {

                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    c[j] = prev[j - 1];
                } else if (p[j - 1] == '*') {
                    c[j] = prev[j] || c[j - 1];
                } else {
                    c[j] = false;
                }
            }
            prev = c;
        }
        return prev[m];
    }
};