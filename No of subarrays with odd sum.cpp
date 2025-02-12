class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> odd(n, 0), even(n, 0);
        if(arr[0] % 2 == 0)even[0] = 1 ;
        else odd[0] = 1;

        int ans = 0;
        for(int i = 1; i < n; i++){
            if(arr[i] % 2 == 0){ 
                odd[i] = odd[i-1];  
                even[i] = 1 + even[i-1]; 
            }
            else{
                odd[i] = 1 + even[i-1];
                even[i] = odd[i-1];
            }

            ans = (ans + odd[i]) % 1000000007;
        }

        return ans + odd[0];
    }
};