class Solution {
public:
    int countVowelStrings(int n) {
        if(n==1) return 5;
        vector<int>v{1,2,3,4,5};
        for(int i=3;i<=n;i++){
        vector<int>tmp;
            for(int j=0;j<5;j++){
                int a=0;
                for(int k=0;k<=j;k++){
                    
                    a+=v[k];
                }
                tmp.emplace_back(a);
            }
            copy(tmp.begin(), tmp.end(), v.begin());

        }
        int ans=0;
        for(int i=0;i<5;i++){
            ans+=v[i];
        }
        return ans;

        
    }
};