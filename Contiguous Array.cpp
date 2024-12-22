class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int prefixSum=0;
        unordered_map<int,int> mpp;
        mpp[0]=-1;
        int n=nums.size(),result=0;
        for(int i=0;i<n;i++) {
            if(nums[i]==1)
                prefixSum+=1;
            else
                prefixSum-=1;
            if(mpp.find(prefixSum) != mpp.end()) {
                result=max(result,i-mpp[prefixSum]);
            }
            else {
                mpp[prefixSum]=i;
            }
        }
        return result;
    }
};