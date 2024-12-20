class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();

        if (n < 10) 
            return {};

        unordered_map<string, int> mp;
        for (int i = 0; i <= n - 10; i++)
        {
            string tmp = s.substr(i, 10);
            mp[tmp]++;
        }

        vector<string> ans;
        for (auto i : mp)
        {
            if (i.second > 1) 
                ans.push_back(i.first);
        }

        return ans;
    }
};