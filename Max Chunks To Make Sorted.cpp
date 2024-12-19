class Solution {
public:
    int ans = 0,n;
    bool check(vector<int>& nums){
        for(int i=0;i<n;i++){
            if(nums[i]!= i){
                cout<<i<<" "<<nums[i]<<" : ";
                return false;
            }
        }
        return true;
    }
    void help(int idx,vector<int> arr,int chuck){
        if(idx == n){
            if(check(arr)){
                ans = max(ans,chuck);
            }
            return;
        }
        for(int i = idx;i<n;i++){
            sort(arr.begin()+idx,arr.begin()+i+1);
            
            help(i+1,arr,chuck+1);
        }
    }
    int maxChunksToSorted(vector<int>& arr) {
        n = arr.size();
        help(0,arr,0);
        return ans;
    }
};