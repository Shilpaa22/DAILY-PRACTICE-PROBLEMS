class Solution {
public:

    string get_key(vector<int> need, int index){
        string key="";
        for(int i=0;i<need.size();i++){
            key+=need[i];
        }
        key+=index;
        return key;
    }

    int apply(vector<int>& price, vector<vector<int>>& special, vector<int> needs, int index, unordered_map<string, int> &mp){
        string key=get_key(needs,index);
        if(mp.find(key)!=mp.end())return mp[key];
        if(index==special.size()){
            int ans=0;
            for(int i=0;i<needs.size();i++){
                ans+=price[i]*needs[i];
            }
            return ans;
        }
        int reject =apply(price, special, needs, index+1, mp);
        mp[key]=reject;
        for(int i=0;i<needs.size();i++){
            if(needs[i]<special[index][i])
                return reject;
            needs[i]-= special[index][i];
        }   
        
        int select=apply(price, special, needs, index, mp)+special[index][needs.size()];
        return mp[key]= min(select, reject);
    } 
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<string, int> mp;
        return apply(price ,special, needs, 0, mp);
    }
};