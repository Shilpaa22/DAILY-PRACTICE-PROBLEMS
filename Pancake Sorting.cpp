class Solution {
public:
vector<int>ans;
    vector<int> pancakeSort(vector<int>& nums) {
        int i=0;
        int largest=nums.size();
        unordered_map<int,int>map;
        
        for(int i=0;i<nums.size();i++)
        map[nums[i]]=i+1;
        
        while(i<nums.size()){
        if(map.find(largest) != map.end()){
            ans.push_back(map[largest]);
            ans.push_back(largest);
            reverse(nums.begin(),nums.begin()+map[largest]);
            reverse(nums.begin(),nums.begin()+largest);
        }
        map.clear();
            for(int i=0;i<nums.size()-1;i++)
        map[nums[i]]=i+1;
        
        largest--;
         i++;
        }
       return ans;
    }
};