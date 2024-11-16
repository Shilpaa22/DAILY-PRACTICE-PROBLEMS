class Solution {
public:
    bool ANS(vector<int> &nums,int k,int k1){
        if(!k1) return k-k1 <=nums[k1] ? true:false;
        else if(k-k1<=nums[k1]) return ANS(nums,k1,k1-1);
        return ANS(nums,k,k1-1);
    }
    bool canJump(vector<int>& nums) {
        if(nums.size() < 2) return 1;
        return ANS(nums,nums.size()-1,nums.size()-2);
    }
};