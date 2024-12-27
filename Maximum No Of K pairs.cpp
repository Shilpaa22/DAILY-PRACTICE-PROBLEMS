class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int i=0;
        int a=0;
        int count=0;
        int j=nums.size()-1;
        sort(nums.begin(),nums.end());
        while(i<j){
            a=nums[i]+nums[j];
            if(a==k)count++,i++,j--;
            else if(a>k) j--;
            else if(a<k) i++;
        }
        return count;
    }
};