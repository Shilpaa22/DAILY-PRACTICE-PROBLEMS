class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int r=nums.size(), c=nums[0].size();
        int ans=0;
        
        for(int i=0;i<r;i++){
           sort(nums[i].begin(),nums[i].end());
        }
        for(int j=0;j<c;j++){
            int val=0;
            for(int i=0;i<r;i++){
                val=max(val,nums[i][j]);
            }
            ans += val;
        }
        return ans;
    }
};