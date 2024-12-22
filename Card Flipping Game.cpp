class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int good = INT_MAX;
        unordered_set<int> set;
        for(int i=0; i<fronts.size(); i++) {
            if (fronts[i] == backs[i]) {
                set.insert(fronts[i]);
            }
        }
        for(int i=0; i<fronts.size(); i++) {
            if (set.find(fronts[i]) == set.end()) {
                good = min(good,fronts[i]);
            }
            if (set.find(backs[i]) == set.end()) {
                good = min(good,backs[i]);
            }
        }
        return good == INT_MAX ? 0 : good;
    }
};