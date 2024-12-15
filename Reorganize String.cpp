class Solution {
public:
    string reorganizeString(string s) {
        string ans=""; 
        map<char,int>map;
        for(int i=0;i<s.length();i++){
            map[s[i]]++;
        }

        vector< pair <int,char> > vect;
        for(auto i : map){
          vect.push_back(make_pair(i.second,i.first));
        }
 
    
         
        sort(vect.begin(),vect.end(),greater<pair <int,char>>());
        ans+=vect[0].second;
        if( vect[0].first>0){
             vect[0].first--;
        }
       for(int i=1;i<s.length();i++){
           sort(vect.begin(),vect.end(),greater<pair <int,char>>());
           if(ans[i-1]!=vect[0].second  ){
              ans.push_back(vect[0].second);
              vect[0].first--;
           }
           else{
               if(vect.size()==1  || vect[1].first<=0 ){
                   return "";
               }
               else{
                   ans.push_back(vect[1].second);
                   vect[1].first--;
              }
             
           }
            
       }

       return ans;
        
    }
};