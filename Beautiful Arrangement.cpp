class Solution {
public:
    int ans = 0;
    int recur(string &vis,int n,int cnt,int toVisit){
        if(cnt==0) {
            if(toVisit==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        int t1,t2;
        t1=t2 =0;
        for(int i=1;i<=n;i++){
            if(!vis[i] and (i%cnt==0 or cnt%i==0)){
                vis[i]=1;
                t1 += recur(vis,n,cnt-1,toVisit-1);
                vis[i]=0;
            }
        }
        return t1;
    }
    int countArrangement(int n) {
        string vis(n,0);
        return recur(vis,n,n,n);
    }
};