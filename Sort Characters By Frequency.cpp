class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        for(auto x : s) {
            m[x]++;
        }
        vector<vector<int>> v;
        for(auto i : m) {
            v.push_back({i.second,(int)i.first});
        }
        sort(v.begin(),v.end(),greater<>());
        string ans = "";
        for(int i = 0;i < v.size();i++) {
            for(int j = 0;j < v[i][0];j++) {
                ans += (char)v[i][1];
            }
        }


        return ans;
    }
};