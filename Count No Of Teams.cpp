class Solution {
public:
    int numTeams(vector<int>& v) {
        int ans = 0, n = v.size();
        
        for (int i = 1; i < n-1; i++) {
            int left_smaller = 0, right_greater = 0;
            
            for (int j = 0; j < n; j++) {
                if (j < i && v[j] < v[i]) 
                    left_smaller++;
                else if (j > i && v[j] > v[i]) 
                    right_greater++;
            }
            
            ans += left_smaller * right_greater;
            
            ans += (i - left_smaller) * (n - i - right_greater - 1);
        }
        
        return ans;
    }
};