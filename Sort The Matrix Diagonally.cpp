class Solution {
public:
   vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

       if(mat.size() == 1) {
            return mat;
        }

        int i = mat.size() - 2;
        int j = 0;

        while(i != 0 || j != mat[0].size() - 1) {
            vector<int> list;
            int m = i;
            int n = j;

             while(m < mat.size() && n < mat[0].size()) {
                list.push_back(mat[m++][n++]);
             }

            sort(list.begin(), list.end());

            m = i;
            n = j;
            for(int l = 0; l < list.size(); l++) {
                mat[m++][n++] = list[l];
            }

            if(i != 0) {
                i--;
            } else {
                j++;
            }
        }
        return mat;
    }
};