class Solution {
public:
    static bool customSort(int a, int b){
        return abs(a) < abs(b);
    }
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(int x : arr) freq[x]++;

        sort(arr.begin(), arr.end(), customSort);

        int count = 0;
        for(int x : arr) {
            int twice = 2*x;
            if(freq[x] > 0 && freq[twice] > 0) {
                freq[twice]--;
                freq[x]--;
                count++;

                if(freq[x] < 0) return false;
            }
        }
        return count >= arr.size()/2;
    }
};