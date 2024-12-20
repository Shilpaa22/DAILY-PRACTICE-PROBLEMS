class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n=routes.size();
        int m=routes[0].size();
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<routes.size();i++)
        {
            for(int stops:routes[i])
            {
                mpp[stops].push_back(i);
            }
        }
        set<int>visbusno,visbustop;
        queue<int>q;
        int c=0;
        q.push(source);
        visbustop.insert(source);
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int bus=q.front();
                q.pop();
                if(bus==target) return c;
                vector<int>temp=mpp[bus];
                for(int i=0;i<temp.size();i++)
                {
                    if(visbusno.find(temp[i])==visbusno.end())
                    {
                        visbusno.insert(temp[i]);
                        for(int k:routes[temp[i]])
                        {
                            if(visbustop.find(k)==visbustop.end())
                            {
                                q.push(k);
                                visbustop.insert(k);
                            }
                        }
                    }
                }
            }
            c++;
        }
        return -1;
    }
};