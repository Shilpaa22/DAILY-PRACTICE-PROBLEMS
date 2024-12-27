
class Solution {
public:
    vector<int> arr;
    Solution(vector<int>& nums) {
        arr = nums;
        
    }
    
    int pick(int target) {
        int len = arr.size();
        int random = 0 + (rand() % len);
        while(arr[random] != target)
            random = 0 + (rand() % len);
        
        return random;
        
    }
};