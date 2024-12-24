class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> record(26,vector<int>(votes[0].size(),0));
        for(auto v:votes){
            for(int i=0;i<votes[0].size();i++){
                record[v[i]-'A'][i]++;
            }
        }
        int tranks = votes[0].size();
        string startingpoint = votes[0];
        sort(startingpoint.begin(),startingpoint.end(),[&](char a, char b){
            for(int i=0;i<tranks;i++){
                if(record[a-'A'][i]!=record[b-'A'][i]) return record[a-'A'][i] > record[b-'A'][i];
            }
            return a<b;
        });
        return startingpoint;
    }
};