class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if(n<2){
            return 1;
        }
        vector<vector<int>> grph(n);
        vector<int> indegree(n,0);
        vector<long long> nodevals(values.begin(),values.end());
        for(auto e:edges){
            int u=e[0],v=e[1];
            grph[u].push_back(v);
            grph[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
        int componentcnt=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            long long addvalue=nodevals[curr]%k==0?0:nodevals[curr];
            if(addvalue==0)componentcnt++;
            for(auto neighbournode:grph[curr]){
                if(indegree[neighbournode]>0){
                indegree[neighbournode]--;
                nodevals[neighbournode]+=addvalue;
                if(indegree[neighbournode]==1)q.push(neighbournode);
                }
            }
        }
        return componentcnt;
    }
};