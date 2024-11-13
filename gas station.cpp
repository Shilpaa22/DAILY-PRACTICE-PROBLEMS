class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(), result=0, remainingFeul=0, total=0;
        for(int i=0;i<n;i++){
            remainingFeul+=(gas[i]-cost[i]);
            if(remainingFeul<0){
                result=i+1;
                remainingFeul=0;
            }
            total+=gas[i]-cost[i];
        }
    return total<0 ? -1 : result;
    }
};