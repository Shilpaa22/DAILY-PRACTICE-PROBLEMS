class Solution {
public:
    bool func(string num1, string num2, string rem){
        if(rem.length() < max(num1.length(), num2.length()))
            return false;
        if(num1[0] == '0' && num1.length() > 1)
            return false;
        if(num2[0] == '0' && num2.length() > 1)
            return false;
        long long a = stol(num1), b = stol(num2);
        long long res = a + b;
        string ans = to_string(res);
        if(ans == rem) return true;
        if(ans.length() > rem.length()) return false;
        int n = ans.length();
        if(ans == rem.substr(0, n)){
            if(n == rem.length()){
                return true;
            }
            a = b;
            b = res;
            rem = rem.substr(n, rem.length() - n);
            return func(to_string(a), to_string(b), rem);
        }
        return false;
    }

    bool isAdditiveNumber(string num) {
        int n = num.length();
        if(n <= 2) return false;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                string num1 = num.substr(0, i + 1);
                string num2 = num.substr(i + 1, j - i);
                string rem = num.substr(j + 1, n - j);
                if(func(num1, num2, rem))
                    return true;
            }
        }
        return false;
    }
};