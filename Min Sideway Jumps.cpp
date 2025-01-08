class Solution {
    int dfs(int i, int j, int n, vector<int> &obs, vector<vector<int>> &dp) {
        if(i == n - 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(obs[i + 1] != j) return dp[i][j] = dfs(i + 1, j, n, obs, dp);
        int up = 1e9, down = 1e9;
        for(int c=1; c<=2; c++) {
            up = min(up, (int)(j + c <= 3 && obs[i] != j + c ? 1 + dfs(i, j + c, n, obs, dp) : 1e9));
            down = min(down, (int)(j - c >= 1 && obs[i] != j - c ? 1 + dfs(i, j - c, n, obs, dp) : 1e9));
        }
        return dp[i][j] = min(up, down);
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return dfs(0, 2, n, obstacles, dp);
    }
};