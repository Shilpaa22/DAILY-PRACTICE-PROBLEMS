class Solution {
public:
    int mod=1e9+7;
    int f(string s,string t,int i,int j,vector<vector<int>>&dp){
        if(j<0) return 1;
        if(i<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int ans;
        if(s[i]==t[j]){
            return dp[i][j]=f(s,t,i-1,j-1,dp)+f(s,t,i-1,j,dp);
        }
        else{
            return dp[i][j]=f(s,t,i-1,j,dp);
        }
    }
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int j=1;j<=m;j++) dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
         return dp[n][m];
    }
};