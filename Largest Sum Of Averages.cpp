class Solution {
public:
    double dp[101][101];
    double help(vector<int>&nums,int k,int i,int j,int n){
        if(i>j or k<=0){
            
            if(k==0 and i==n) return 0;
            else return INT_MIN/2;
        }
        if(dp[i][k]!=0) return dp[i][k];
        int sum=0;
        double temp=INT_MIN/2.0;
        for(int c=i;c<=j;c++){
            sum+=nums[c];
            double avg=(sum*1.0)/(c-i+1);
            temp=max(temp,avg+help(nums,k-1,c+1,j,n));
        }
        return dp[i][k]=temp;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n=nums.size();
        memset(dp,0,sizeof(dp));
        return help(nums,k,0,n-1,n);
    }
};