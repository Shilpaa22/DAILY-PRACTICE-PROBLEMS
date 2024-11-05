class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int col = matrix[0].size();
        vector<bool> rowZero(rows, false);
        vector<bool> colZero(col, false);

        for(int i=0; i<rows; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == 0){
                    rowZero[i] = true;
                    colZero[j] = true; 
                }
            }
        }

        for(int i=0; i<rows; i++){
            for(int j=0; j<col; j++){
                if(rowZero[i] || colZero[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};