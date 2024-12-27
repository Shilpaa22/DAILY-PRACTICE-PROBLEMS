class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        string temp="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
            {
                temp+=s[i];
            }
            else{
                if(!temp.empty()){
                    v.push_back(temp);
                    temp="";
                }
            }
        }
        if(!temp.empty()) v.push_back(temp);
        string res="";
        for(int i=v.size()-1;i>=0;i--)
        {
            res+=v[i];
            if(i>0)
                res+=" ";
        }
        return res;
    }
};