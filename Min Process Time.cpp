class Solution {
public:
    int minProcessingTime(vector<int>& p, vector<int>& t) {
        int n = t.size(), res = 0;
        sort(p.begin(),p.end());
        sort(t.begin(),t.end(),greater<int>());
        for(int i = 0;i<n;i+=4) res = max(res,p[i/4]+t[i]);
        return res;
    }
};