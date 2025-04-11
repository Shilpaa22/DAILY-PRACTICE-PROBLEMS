class Solution {
public:
    int subarrayBitwiseORs(vector<int>& nums) {

        unordered_set<int> st;
        int n = nums.size();
        int r = 0;
        unordered_map<int, int> prev;

        while (r < n) 
        {
            unordered_map<int, int> curr;

            int val = nums[r];
            for (auto it : prev) 
            {
                curr[val | it.first] += it.second;
                st.insert(val | it.first);
            }
            curr[val]++;
            st.insert(val);

            prev = curr;

            r++;
        }
        return st.size();
    }
};