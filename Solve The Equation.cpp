class Solution {
public:
    string solveEquation(string equation) {
        int c = 0, c1 = 0;
        int s = 1, n = equation.size(), i = 0;
        while (i < n) {
            if (equation[i] == '=') {
                s = -1;
                i++;
                continue;
            }
            int curr = s;
            if (equation[i] == '+' || equation[i] == '-') {
                curr = (equation[i] == '-') ? -s : s;
                i++;
            }
            int num = 0;
            bool temp = false;
            while (i < n && isdigit(equation[i])) {
                num = num * 10 + (equation[i] - '0');
                i++;
                temp = true;
            }
            if (i < n && equation[i] == 'x') {
                if (!temp) num = 1;
                c += curr * num;
                i++;
            } else {
                c1 += curr * num;
            }
        }
        if (c == 0 && c1 == 0) return "Infinite solutions";
        if (c == 0) return "No solution";
        int x = -c1 / c;
        return "x=" + to_string(x);
    }
};