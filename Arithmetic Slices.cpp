class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        int currCount=0;
        for(int i=2;i<nums.size();++i){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                currCount++;
                continue;
            }
            else{
                ans+=((currCount)*(currCount+1))/2;
                currCount=0;
            }
        }
        ans+=((currCount)*(currCount+1))/2;
        return ans;
    }
};