class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
        int sum=0,moves=0,i=1;
        while(true){
            sum+=i;
            i++;
            moves++;
            if(sum==target)return moves;
            if(sum>target && (sum-target)%2==0)return moves;
        }
        return moves;
    }
};