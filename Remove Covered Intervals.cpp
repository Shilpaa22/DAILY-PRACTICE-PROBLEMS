class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end());
        int st = inter[0][0],end = inter[0][1],ans = 0;
        for(int i = 1;i<inter.size();i++)
        {
            if(inter[i][0]>=st && inter[i][1]<=end) ans++;
            else if(inter[i][0]==st && inter[i][1]>=end)
            {
                ans++;
                end = inter[i][1];
            }
            else if(inter[i][0]>=end || inter[i][1]>=end)
            {
                st = inter[i][0];
                end = max(end,inter[i][1]);
            }
        }
        return inter.size()-ans;   
    }
};