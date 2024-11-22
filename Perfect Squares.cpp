class Solution {
public:
    int numSquares(int n) {
    int dp[(int)sqrt(n)+1][n+1];
    memset(dp,-1,sizeof dp);
    auto fn = [&](auto&&fn,int i,int sum) -> int {
        if(sum == 0) return 0;
        if(i*i > n) return 1e9;
        if(dp[i][sum] != -1) return dp[i][sum];
        int ex = fn(fn,i+1,sum);
        int in = 1e9;
        if(i*i <= sum)
            in = 1 + fn(fn,i,sum-(i*i));
        return dp[i][sum] = min(ex,in);
    };
        return fn(fn,1,n);
    }
};