class Solution {
    public:
        vector<int>ans;
        void dp(int i,int sum,vector<int>&toppingCosts,int &target){
            if(i==toppingCosts.size()){
                ans.push_back(sum);return;
            }
            for(int t=0;t<=2;t++){
                dp(i+1,sum+toppingCosts[i]*t,toppingCosts,target);
            }
            return;
        }
        int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
            for(auto x:baseCosts){
                dp(0,x,toppingCosts,target);
            }
            int t=INT_MAX;
            sort(ans.begin(),ans.end());
            for(auto x:ans){
                if(x<=target){
                    t=x;
                }else if(x>target&&abs(x-target)<abs(t-target)){
                    t=x;
                }
            }
            return t;
        }
    };