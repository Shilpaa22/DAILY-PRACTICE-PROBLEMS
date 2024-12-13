class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1)
            return s;

        vector<string> arr(numRows, "");
        int i = 0, j = 1;

        for(const auto& ch : s) {
            arr[i].push_back(ch);
            i += j;

            if(i == 0 || i == numRows - 1)
                j = -j;
        }

        string ans = "";
        for(const auto& str : arr)
            ans += str;

        return ans;
    }
}; 