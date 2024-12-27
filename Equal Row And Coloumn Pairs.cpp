class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<string> row;
        vector<string> col;
        
        for(int i=0;i<n;i++)
        {
            string rowStr = "";
            for(int j=0;j<n;j++)
            {
                rowStr += to_string(grid[i][j]) + ",";
            }
            row.push_back(rowStr);
        }

        for(int i=0;i<n;i++)
        {
            string colStr = "";
            for(int j=0;j<n;j++)
            {
                colStr += to_string(grid[j][i]) + ",";
            }
            col.push_back(colStr);
        }

        int ans = 0;

        for(int i=0;i<row.size();i++)
        {
            for(int j=0;j<col.size();j++)
            {
                if(row[i] == col[j])
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};