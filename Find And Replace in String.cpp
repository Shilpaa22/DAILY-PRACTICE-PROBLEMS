class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        
        
       map<int,pair<string,string>>hash;
        
        int n=indices.size();
        int i;
        for(i=0;i<n;i++)
        {
            int start_idx=indices[i];
            string have=sources[i];
            string convert=targets[i];
            
            if(s.substr(start_idx,have.size())==have)
            hash[start_idx]={have,convert};
        }
        int start=0;
        string res="";
        while(start<s.size())
        {
            if(hash.find(start)!=hash.end())
            {
                    res+=hash[start].second;
                start+=hash[start].first.size();
            
            }
            else
            {
                 res+=s[start];
                start++;
               
            }
        }
        
        return res;
    }
};