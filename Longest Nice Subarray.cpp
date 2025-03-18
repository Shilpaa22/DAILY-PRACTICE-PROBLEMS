class Solution {
    public:
        bool isNice(int a,int b){
            if(a&b) return false;
            return true;
        }
        int longestNiceSubarray(vector<int>& nums) {
            int n=nums.size();
            if(n==1) return 1;
            int left=0;
            int right=1;
            int longest=1;
            bool noNice=false;
            for(right;right<n;right++){
                noNice=false;
                for(int i=left;i<right;i++){
                    if(!isNice(nums[i],nums[right])){
                        noNice=true;
                        break;
                    }
                }
                if(noNice){
                   left++; 
                   right--;
                }
                else{
                    longest=max(longest,right-left+1);
                }
            }
            return longest;
        }
    };