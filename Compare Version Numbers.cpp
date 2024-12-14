class Solution {
public:
    void convert(string s,vector<int>&iv1){
        vector<string>v1;
        int prev=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='.'){
                string temp=s.substr(prev,i-prev);
                prev=i+1;
                v1.push_back(temp);
            }
        }
        v1.push_back(s.substr(prev,s.size()-prev));
        for(int i=0;i<v1.size();i++){
            iv1[i]=(stoi(v1[i]));
        }
    }
    int compareVersion(string s, string s2) {
        int n1=s.size();
        int n2=s2.size();
        int n=max(n1,n2);

        vector<int>iv1(n,0);
        convert(s,iv1);

        vector<int>iv2(n,0);
        convert(s2,iv2);

        for(int i=0;i<n;i++){
            if(iv1[i]>iv2[i])return 1;
            if(iv1[i]<iv2[i])return -1;
        }
        return 0;
        
    }
};