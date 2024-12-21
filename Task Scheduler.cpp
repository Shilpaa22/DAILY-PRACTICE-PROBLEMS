class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       vector<int>freq(26,0);
       for(int i=0;i<tasks.size();i++){
        freq[tasks[i]-'A']++;
       }
       int maxi=0;
       for(int i=0;i<26;i++){
        maxi=max(maxi,freq[i]);
       }
       int count=0;
       for(int i=0;i<26;i++){
        if(freq[i]==maxi)count++;
       }
       int val=((maxi-1)*(n+1))+count;
       int ans=max(val,(int)tasks.size());
       return ans;
    }
};