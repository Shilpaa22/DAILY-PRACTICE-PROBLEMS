class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
 return backtrack(nums,target,0,0);
    }
    int cnt = 0;
    long long backtrack(vector<int>& nums , long long target , long long sum , long long i) {
        if (i == nums.size()) {
        return (sum == target) ? 1 : 0;
        }
            return backtrack(nums, target, sum + nums[i], i + 1) +
               backtrack(nums, target, sum - nums[i], i + 1);
    }
};