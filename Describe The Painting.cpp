class Solution {
public:
    using ll=long long ;
    vector<vector<long long>> splitPainting(vector<vector<int>>& nums) 
    {
        vector<vector<ll>>ans;
        map<ll,ll>mp;
        for(auto it:nums)
        {
            mp[it[0]]+=it[2];
            mp[it[1]]-=it[2];
        }
        ll sum=0;
        ll prev=0;
        for(auto&it:mp)
        {
            if(sum>0)
            {
                ans.push_back({prev,it.first,sum});
            }
            sum+=it.second;
            prev=it.first;
        }
        return ans;
    }
};