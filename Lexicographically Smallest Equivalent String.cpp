class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        string ans;
        int n=s1.length();
        int mp[26];
        for(int i=0;i<26;i++){
          mp[i]='a'+i;
        }
        for(int i=0;i<n;i++){
            int mx=max(mp[s1[i]-'a'],mp[s2[i]-'a']);
             int mn=min(mp[s1[i]-'a'],mp[s2[i]-'a']);
             for(int i=0;i<26;i++){
                 if(mp[i]==mx)mp[i]=mn;
             }
        }
        for(int i=0;i<baseStr.size();i++){
            baseStr[i]=mp[baseStr[i]-'a'];
        }
        return baseStr;
    }
};