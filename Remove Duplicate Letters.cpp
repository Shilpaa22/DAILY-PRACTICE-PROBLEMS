class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack <char> st;
        unordered_map<int,int> m;
        for(auto i:s)
        {
            m[i]++;
        }
        st.push(s[0]);
        m[s[0]]--;
       
        vector<bool> temp(26,false);
         temp[s[0]-'a']=true;
        for(int i=1;i<s.size();i++)
        { 
            if(temp[s[i]-'a']==true)
            {
                m[s[i]]--;
            continue;
            }
            while(!st.empty() && s[i]<st.top() && m[st.top()]>=1)
            {    
                temp[st.top()-'a']=false;
                    st.pop(); 
                    
            }

            st.push(s[i]);
            temp[s[i]-'a']=true;
             m[s[i]]--;
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};