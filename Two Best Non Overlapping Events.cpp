class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<pair<int, int>> start, end;

        for(const auto &it: events) {
            start.push_back({it[0], it[2]});
            end.push_back({it[1], it[2]});
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int si = 0, ei = 0, mxe = 0, ans = 0;

        while(si < events.size()) {
            while(end[ei].first < start[si].first) {
                mxe = max(mxe, end[ei].second);
                ei++;
            }

            ans = max(ans, start[si].second + mxe);

            si++;
        }

        return ans;
    }
};