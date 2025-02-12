class Solution {
public:
    int helper(int i, vector<int>& nums, int k, int op1, int op2, vector<vector<vector<int>>>& dp) {
        if (i >= nums.size()) return 0;
        if (dp[i][op1][op2] != -1) return dp[i][op1][op2];
        
        int take1 = 1e9, take2 = 1e9, take3 = 1e9, take4 = 1e9;
        
        if (op1 > 0 && op2 > 0 ) {
            int a = round(nums[i] / 2.0);
            if (a >= k) a -= k;
            int b = nums[i] >= k ? nums[i] - k : nums[i];
            b =round(b/2.0);
            take1 = min(a, b) + helper(i + 1, nums, k, op1 - 1, op2 - 1, dp);
        }
        if (op1 > 0) {
            take2 = round(nums[i] / 2.0) + helper(i + 1, nums, k, op1 - 1, op2, dp);
        }
        if (op2 > 0 && k <= nums[i]) {
            take3 = nums[i] - k + helper(i + 1, nums, k, op1, op2 - 1, dp);
        }
        take4 = nums[i] + helper(i + 1, nums, k, op1, op2, dp);

        return dp[i][op1][op2] = min({take1, take2, take3, take4});
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(op1 + 1, vector<int>(op2 + 1, -1)));
        return helper(0, nums, k, op1, op2, dp);
    }
};
