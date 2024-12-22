class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        unordered_map<int,int> mp;
        for(auto i:barcodes) mp[i]++;
        priority_queue<pair<int,int>> pq;
        for(auto j:mp) pq.push({j.second,j.first});
        vector<int> ans(n);
        int j = 0;
        while(!pq.empty()){
            int cnt = pq.top().first;
            int a = pq.top().second;
            //if(j>=n) j=1;
            while(cnt--){
                ans[j] = a;
                j+=2;
                if(j>=n) j=1;
            }
            pq.pop();
        }
        return ans;
    }
};