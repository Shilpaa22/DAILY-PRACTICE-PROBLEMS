class Solution {
public:
    int countSubarrays(vector<int>&arr,int x){
        int n=arr.size();
        int subarrays=1,subarraysum=0;
        for(int i=0;i<n;i++) if(subarraysum+arr[i]<=x) subarraysum+=arr[i];
        else{
            subarrays++;
            subarraysum=arr[i];
        }
        return subarrays;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(begin(nums),end(nums));
        int high=accumulate(begin(nums),end(nums),0);
        while(low<=high){
            int mid=(low+high)/2;
            if(countSubarrays(nums,mid)>k) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};