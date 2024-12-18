class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        int aCount = 0, bCount = 0, cCount = 0;

        while (a > 0 || b > 0 || c > 0) {
           
            if ((a >= b && a >= c && aCount < 2) || (bCount == 2 && a > 0) ||
                (cCount == 2 && a > 0)) {
                res += 'a';
                a--;
                aCount++;
                bCount = 0;
                cCount = 0;
            }
         
            else if ((b >= a && b >= c && bCount < 2) ||
                     (aCount == 2 && b > 0) || (cCount == 2 && b > 0)) {
                res += 'b';
                b--;
                bCount++;
                aCount = 0;
                cCount = 0;
            }
            else if ((c >= a && c >= b && cCount < 2) ||
                     (aCount == 2 && c > 0) || (bCount == 2 && c > 0)) {
                res += 'c';
                c--;
                cCount++;
                aCount = 0;
                bCount = 0;
            }
            else{
                break;
            }
        }

        return res;
    }
};