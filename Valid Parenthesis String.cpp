class Solution {
public:
    bool checkValidString(string s) {
        int size = s.size();
        int leftmin=0, leftmax=0;
        for(auto i : s){
            if(i=='('){
                leftmin++;
                leftmax++;
            }
            else if( i==')'){
                leftmax--;
                leftmin--;
            }
            else if(i=='*'){
             leftmin--;
             leftmax++;
            }
            if(leftmin<0)
            leftmin=0;
            if(leftmax<0)
            return false;
        }
        if(!leftmin){
           return true;
        }
        else{
            return false;
        }
    }
};