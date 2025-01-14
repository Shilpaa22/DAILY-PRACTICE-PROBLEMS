class Solution {
public:
    static constexpr int combinations[10] = { 0, 0, 3, 3, 3, 3, 3, 4, 3, 4 };
    static constexpr int mod = 1000000007;
    int countTexts(string& pressedKeys) {
        int dp[6] = {1, 1};

        int len = 2, maxLen = combinations[pressedKeys[0]-'0'];
        for (int i = 1; i < pressedKeys.size(); i++) {
            if (pressedKeys[i] != pressedKeys[i-1]) {
                maxLen = combinations[pressedKeys[i]-'0'];
                dp[0] = dp[1] = dp[len-1];
                dp[2] = dp[3] = dp[4] = 0;
                len = 2;
                continue;
            }
            for (int j = 1; j <= len; j++) {
                dp[len] += dp[len-j];
                dp[len] %= mod;
            }
            if (len == maxLen)
                for (int i = 0; i <= len; i++)
                    dp[i] = dp[i+1];
            len = min(len + 1, maxLen);
        }
        return dp[len-1];
    }
};