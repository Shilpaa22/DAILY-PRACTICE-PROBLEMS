class Solution {
public:
    vector<int>solve(string s, int ind){
        int n=0;
        while(ind<s.size()){
            if(s[ind]=='.') break;
            else n=n*10 + (s[ind]-'0');
            ind++;
        }
        return {n,ind+1};
    } 

    int compareVersion(string version1, string version2) {
        int i=0,j=0,ans=0;
        vector<int>ans1,ans2;

        while(i < version1.size() || j < version2.size()){
            ans1=solve(version1,i);
            ans2=solve(version2,j);
            int v1=ans1[0], v2=ans2[0];
            i=ans1[1]; j=ans2[1];
            if(v1<v2) return -1;
            else if(v1>v2) return 1;
    }
    return 0;
    }
};