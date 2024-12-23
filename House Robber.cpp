class Solution {
public:
    int house(vector<int> arr,int i,vector<int>& dp) {
        if(i == arr.size()-1) return arr[i];
        if(i == arr.size()-2) return max(arr[i],arr[i+1]);
        if(dp[i] != -1) return dp[i];
        dp[i] = max( arr[i]+house(arr,i+2,dp) , 0+house(arr,i+1,dp) );
        return dp[i];
    }
    int home(vector<int>& arr,vector<int>& dp){
        int n = arr.size();
        if(n == 1) return arr[0];
        dp[n-1] = arr[n-1];
        dp[n-2] = max(arr[n-1],arr[n-2]);
        for(int i=n-3; i>=0; i--) {
            dp[i] = max( arr[i]+dp[i+2] , 0+dp[i+1] );
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return home(nums,dp);
    }
};