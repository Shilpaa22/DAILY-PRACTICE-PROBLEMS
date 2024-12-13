class Solution {
public:

    bool isPredecessor(const string &a, const string &b) {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
                j++;
            }
            else j++;
        }
        return i == a.size();
    }

    int longestStrChain(vector<string>& w) {
        int n = w.size();
        
        sort(w.begin(), w.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        
        vector<int> dp(n, 1);
        int maxLength = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (w[i].size() == w[j].size() + 1) {
                    if (isPredecessor(w[j], w[i])) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        return maxLength;
    }


};