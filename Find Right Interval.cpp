class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        map<int, int> mpp;

        for(int i=0; i<n; i++){  
            mpp.insert({intervals[i][0], i});
        }

        vector<int> ans;
        for(int i=0; i<intervals.size(); i++){
            int tgt = intervals[i][0];
            auto res = mpp.lower_bound(intervals[i][1]);
            if(res != mpp.end()) 
                ans.push_back(res->second);
            else 
                ans.push_back(-1);
        }
        return ans;
    }
}; 