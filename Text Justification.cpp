class Solution {
public:
    vector<string> fullJustify(vector<string>& arr, int k) {
        int l = 0, r = 0;
        vector <pair <int, int> > p;
        vector <string> ans;

        for (int i = 0; i < arr.size(); i++) {
            if (r + arr[i].size() + (i - l) <= k) {
                r += arr[i].size();
            }
            else {
                p.push_back({l, i - 1});
                l = i;
                r = arr[i].size();
            }
        }p.push_back({l, arr.size() - 1});

        for (auto i : p) {

            if (i.first == p.back().first && i.second == p.back().second) break;

            string pp = "";
            int c = 0;
            for (int j = i.first; j <= i.second; j++) {
                c += arr[j].size();
            }

            int cmp = k;
            if (i.second - i.first == 0) {
                pp += arr[i.second];
                cmp -= arr[i.second].size();

                while (cmp > 0) pp += " ", cmp--;

                ans.push_back(pp);
                continue;
            }
            int s = (k - c) % (i.second - i.first), tmp = (k - c) / (i.second - i.first);
            for (int j = i.first; j <= i.second; j++) {
                pp += arr[j]; 
                cmp -= arr[j].size();

                if (cmp == 0)break;
                for (int l = 0; l < tmp; l++) {
                    if (cmp == 0) break;
                    pp += " ", cmp--;
                }
                if (s > 0 && cmp > 0) pp += " ", s--, cmp--;
            }
            while (cmp > 0) pp += " ", cmp--;
            ans.push_back(pp);
        }
            int c = 0, cmp = k;
            string pp = "";
            for (int j = p.back().first; j <= p.back().second; j++) {
                c += arr[j].size();
            }
            for (int j = p.back().first; j <= p.back().second; j++) {
                pp += arr[j];
                cmp -= arr[j].size();

                if (cmp == 0)break;
                pp += " ";
                cmp--;
            }
            while (cmp > 0) pp += " ", cmp--;

            ans.push_back(pp);
        return ans;
    }
};