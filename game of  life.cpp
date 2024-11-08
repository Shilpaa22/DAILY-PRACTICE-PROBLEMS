class Solution {
public:
    vector<int> countlivedead(int row, int col, vector<vector<int>>& board){
        int n= board.size(), m=board[0].size();
        int delr[] = {-1,-1,-1,0,1,1,1,0};
        int delc[] = {-1,0,1,1,1,0,-1,-1};
        int live=0, dead = 0;
        for(int i=0; i<8; i++){
            int nrow = row+delr[i], ncol=col+delc[i];
            if(nrow<0 || nrow>=n || ncol<0 || ncol>=m) continue;
            if(board[nrow][ncol]) live++;
            else dead++;
        }
        return {live,dead};
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n= board.size(), m=board[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                vector<int>it = countlivedead(i,j,board);
                if(board[i][j] == 0){
                    if(it[0]==3) ans[i][j] = 1;
                }else{
                    if(it[0]>=2 && it[0]<=3) ans[i][j] = 1;
                }
            }
        }
        board = ans;
    }
};