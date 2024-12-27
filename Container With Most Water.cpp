class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int ans = INT_MIN;
        int i = n-1; 
        while(l<r){
            int area = i * min(height[l],height[r]);
            ans = max(area,ans);
            i--;
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};