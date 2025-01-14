class Solution {
public:

    int solve(vector<int>& nums1, vector<int>& nums2, int ind1, int ind2,
     vector<vector<int>> &dp){
        if(ind1==nums1.size() or ind2==nums2.size())return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(nums1[ind1]==nums2[ind2]){
            return dp[ind1][ind2]=1+solve(nums1, nums2, ind1+1, ind2+1, dp);
        }
        return dp[ind1][ind2]= max(solve(nums1, nums2, ind1+1, ind2, dp), 
        solve(nums1, nums2, ind1, ind2+1, dp));
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(nums1, nums2, 0, 0, dp);
    }
};