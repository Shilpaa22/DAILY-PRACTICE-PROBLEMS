class Solution {
public:

    bool digichecker(int i){
        vector<int> a ;
        while(i){
            a.push_back(i % 10);
            i = i / 10;
        }
        for(int i = 0 ; i < a.size() ; i++){
            if(a[i] == 3 || a[i] == 4 || a[i] == 7){
                return false ;
            }
        }
        return true ;
    }

    bool nonsame(int i){
        int x = i ;
        vector<int> a ;
        while(x){
            int y = x % 10 ;
            if(y == 0 || y == 1 || y == 8){
                y = x % 10 ;
            }
            else if(y == 2){
                y = 5 ;
            }
            else if( y == 5){
                y = 2 ;
            }
            else if(y== 9){
                y = 6 ;
            }
            else if(y==6){
                y = 9 ;
            }
            x = x / 10 ;
            a.push_back(y);
        }
        int number = 0 ;
        for(int i = a.size() - 1 ;i >= 0 ; i--){
            number = number*10 + a[i];
        }
        if(number == i){
            return false ;
        }
        else{
            return true ;
        }
    }

    int rotatedDigits(int n) {
        int count = 0 ;
        for(int i = 1 ; i <= n ; i++){
               bool checker = digichecker(i);
               if(checker){
                bool checklast = nonsame(i) ;
                if(checklast){
                    count++;
                }
               }
            }
        
        return count ;
    }
};