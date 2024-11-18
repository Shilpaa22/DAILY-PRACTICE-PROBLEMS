class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ps(n, 0);
        ps[0] = code[0];
        for (int i = 1; i < n; i++)
            ps[i] = ps[i - 1] + code[i];
        for (int i = 0; i < n; i++) {
            if (k == 0) {
                code[i] = 0;
                continue;
            }
            if (k > 0) {
                if (i + 1 + k > n) {
                    code[i] = ps[n - 1] + ps[(i + k) % n] - ps[i];   
                } else {
                    code[i] = ps[i + k] - ps[i];          
                }
               
            } else {
                int h = -1 * k;
                if (i - 1 - h < 0) {
                    code[i] = ps[n - 1]  - ps[n - 1 - (h - i)] + (i > 0 ? ps[i - 1] : 0);                   
                } else {               
                    code[i] = ps[i - 1] - ps[i-1-h];
                }
                
            }
               
        }
        return code;
    }
};