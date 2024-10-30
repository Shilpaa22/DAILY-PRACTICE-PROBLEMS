class Solution {
    public int countKConstraintSubstrings(String s, int k) {
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int zeroCount = 0;
            int oneCount = 0;
            for (int j = i; j < n; j++) {
                if (s.charAt(j) == '0') {
                    zeroCount++;
                } else {
                    oneCount++;
                }
                
                if (zeroCount <= k || oneCount <= k) {
                    count++;
                }
            }
        }
        
        return count;
    }
}