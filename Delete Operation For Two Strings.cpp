class Solution {
public:
int lcs(string s1,string s2){
        int n=s1.size();
        int m=s2.size();
        vector<int>prev(m+1,0),curr(m+1,0);
        for(int i=0;i<=m;i++)prev[i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])curr[j]=1+prev[j-1];
                else curr[j]=max(curr[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[m];
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        return (n-lcs(word1,word2))+(m-lcs(word1,word2));
    }
};