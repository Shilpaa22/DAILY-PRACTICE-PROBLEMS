class Solution {
public:
    string customSortString(string order, string s) {
    unordered_multiset<char>set2(s.begin(),s.end());
    string str = "";
    for(char x : order){
        while(set2.find(x)!=set2.end()){
             str += x;
             auto it = set2.find(x);
             set2.erase(it); 
         }
     }
     for(auto x : set2){
         str += x;
     }
     return str;
    }
};