class Solution {
public:
  string maxValue(string n, int x) {
        int sz=n.size(),positive=1;
        if(n[0]=='-') positive=0;
        
        if(positive){
            for(int i=0;i<sz;++i){
                if(n[i]-'0'<x) {
                    n.insert(n.begin()+i, x+'0');
                    return n;
                }
            }
        }
        
        else{
            for(int i=1;i<sz;++i){
                if(n[i]-'0'>x) {
                    n.insert(n.begin()+i, x+'0');
                    return n;
                }
            }
        }
        
        n.insert(n.begin()+sz, x+'0');
        return n;
    }
};