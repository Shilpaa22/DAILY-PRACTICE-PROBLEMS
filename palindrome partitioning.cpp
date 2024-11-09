class Solution {
public:
    bool checkPali(string& s,int l,int r){
        while(l<r){
            if(s[l++]!=s[r--]) return false;
        }
        return true;
    }
    void solve(int ind,vector<string>&ds,vector<vector<string>>&ans,string& s){
        if(ind==s.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=ind+1;i<=s.size();i++){
            if(checkPali(s,ind,i-1)==true){
                ds.push_back(s.substr(ind,i-ind));
                solve(i,ds,ans,s);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        solve(0,ds,ans,s);
        return ans;
    }
};