class Solution {
private:
    int solve(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        if(nums[0]!=0) ans++;
        if(nums[n-1] < n) ans++;
        for(int i=0; i<n-1; ++i ) {
            int t = i+1;
            if(t>nums[i] && t<nums[i+1]) ans++;
        }
        return ans;
    }
public:
    int countWays(vector<int>& nums) {
        return solve(nums);
    }
};