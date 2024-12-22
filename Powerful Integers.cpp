class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_map<int, int> xp;
        map<pair<int,int>, int> powvk;
        vector<int> ans;
        int fst = 0, snd = 0;
        if(x == 1 && y == 1 && bound > 1) return {2};
        if(bound <= 1) return {};
        if(bound == 2) return {2};
        if(x == 1)
        {
            ans.push_back(2);
            int dbl = y;
            while(dbl+1 <= bound)
            {
                ans.push_back(dbl+1);
                dbl *= y;
            }
            return ans;
        }
        if(y == 1)
        {
            ans.push_back(2);
            int dbl = x;
            while(dbl+1 <= bound)
            {
                ans.push_back(dbl+1);
                dbl *= x;
            }
            return ans;
        }
        //int xf = 1, yf = 1;
        //ans.push_back()
        while(true)
        {
            int xfst, ysnd;
            if(powvk.count({x,fst}))
            {
                xfst = powvk[{x,fst}];
            }
            else
            {
                xfst = pow(x,fst);
                powvk[{x,fst}] = xfst;
            }
            if(powvk.count({y,snd}))
            {
                ysnd = powvk[{y,snd}];
            }
            else
            {
                ysnd = pow(y,snd);
                powvk[{y,snd}] = ysnd;
            }
            long long int val = xfst + ysnd;
            if(val > bound)
            {
                if(snd == 0) break;
                fst++;
                snd = 0;
            }
            else
            {
                xp[val]++;
                snd++;
            }
        }
        for(auto &[first, second] : xp)
            ans.push_back(first);
        return ans;
    }
};