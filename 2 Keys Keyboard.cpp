class Solution {
public:
    int minSteps(int n) {
        int s{0};
        for (auto i{2}; i <= n; ++i)
            for (; n % i == 0; s += i, n /= i);
        return s;
    }
};
