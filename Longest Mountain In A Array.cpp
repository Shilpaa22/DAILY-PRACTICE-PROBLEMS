class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size(),ans=0,count;
        vector<int>peaks;
        for(int i=1;i<(n-1);i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                peaks.push_back(i);
            }
        }
        int m = peaks.size();
        for(int i=0;i<m;i++){
            count = 1;
            for(int j=peaks[i];j>0;j--){
                if(arr[j]>arr[j-1]){
                    count++;
                }
                else{
                    break;
                }
            }
            for(int j=peaks[i];j<(n-1);j++){
                if(arr[j]>arr[j+1]){
                    count++;
                }
                else{
                    break;
                }
            }
            if(ans<count){
                ans = count;
            }
        }
        return ans;
    }
};