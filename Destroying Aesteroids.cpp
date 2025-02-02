class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& v) 
    {
        sort(v.begin(),v.end());

        long long ans=mass;
        for(long long i=0;i<v.size();i++)
        {
            if(ans<v[i])
                return false;
            ans+=v[i];
        }
        
        return true;
    }
};