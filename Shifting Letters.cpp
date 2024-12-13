class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false); 
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    string shiftingLetters(string s, vector<int>& shifts) {
        long long ps=0;
        for(int i=s.length()-1;i>=0;i--){
            ps+=shifts[i];
            s[i]=(char)((((s[i]-'a')+ps)%26)+'a');
        }
        return s;
    }
};