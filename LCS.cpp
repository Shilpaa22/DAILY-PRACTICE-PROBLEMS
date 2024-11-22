class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0)
        { return 0; }

        int longest = 1;
        int current = 1;

        unordered_set<int> sett(nums.begin(), nums.end());

        for(auto it: sett)
        {
            if(sett.find(it-1) == sett.end()) 
            {
                current = 1;    
                int x = it;

                while(sett.find(x+1) != sett.end()) 
                {
                    x = x + 1;
                    current++;
                }
                longest = max(longest,current);
            }
        }
        return longest;
    }
};