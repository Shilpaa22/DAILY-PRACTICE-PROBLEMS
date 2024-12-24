class TopVotedCandidate {
public:
    map<int,int>m;
    TopVotedCandidate(vector<int>& p, vector<int>& times) {
        unordered_map<int,int>mp;
        int curr=-1;
        for(int i=0;i<p.size();i++){
            curr=(++mp[p[i]]>=mp[curr]?p[i]:curr);
            m[times[i]]=curr;
        }
    }
    
    int q(int t) {
        return (--m.upper_bound(t))->second;
    }
};

