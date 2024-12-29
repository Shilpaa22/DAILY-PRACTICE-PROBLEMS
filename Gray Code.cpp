class Solution {
public:

    vector<int> grayCode(int n) {
        vector<int>ans;
        int b = pow(2,n);
        for(int i=0;i<b;i++)
        {
            ans.push_back(i^(i>>1));
        }
        return ans;
    }
};