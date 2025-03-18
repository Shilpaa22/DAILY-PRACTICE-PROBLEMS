class Solution {
    public:
        const int mod = 1e9 + 7;
        long long dp[5][4][5005];
        long long func(int i, int j, int n) {
            if(i < 0 || i >= 4 || j < 0 || j >= 3) return 0;
            if((i == 3) && (j == 0 || j == 2)) return 0;
            if(n == 0) return 1;
            if(dp[i][j][n] != -1) return dp[i][j][n] % mod;
    
            long long count = 0;
            int delRow[] = {-2, -2, -1, -1, 1, 1, 2, 2};
            int delCol[] = {-1, 1, -2, 2, -2, 2, -1, 1};
            for(int k = 0; k < 8; k++) {
                int ni = i + delRow[k];
                int nj = j + delCol[k];
                count += func(ni, nj, n - 1) % mod;
            }
    
            return dp[i][j][n] = count % mod;
        }
    
        int knightDialer(int n) {
            memset(dp, -1, sizeof(dp));
            int ans = 0;
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 3; j++) {
                    ans = (ans + func(i, j, n - 1)) % mod;
                }
            }
            return ans % mod;
        }
    };