class Solution {
   public:
      int deleteAndEarn(vector < int > & nums) {
          int N = 10001;
          int freq[N];
          memset(freq, 0, sizeof freq);
          int dp[N];
          
          for (int num : nums){
              freq[num] += num;
          }
          dp[0] = 0;
          dp[1] = freq[1];
          for (int i = 2 ; i < N ; i++){
              dp[i] = max(dp[i - 1], dp[i - 2] + freq[i]);    
          }
          return dp[N - 1];
      }
};