class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        int nr, nc;
        nr=grid.size();
        nc=grid[0].size();
        if (nr==0)
            return;
        grid[r][c]='0';
        if(r-1>=0 && grid[r-1][c]=='1'){dfs(grid, r-1,c);}
        if(r+1<nr && grid[r+1][c]=='1'){dfs(grid, r+1,c);}
        if(c-1>=0 && grid[r][c-1]=='1'){dfs(grid, r,c-1);}
        if(c+1<nc && grid[r][c+1]=='1'){dfs(grid, r,c+1);}
    }
    int numIslands(vector<vector<char>>& grid) {
        int num_row, num_col;
        num_row=grid.size();
        num_col=grid[0].size();
        
        int i,j, num_island=0;
        for(i=0; i<num_row; i++)
        {
            for(j=0; j<num_col; j++)
            {
                if(grid[i][j]=='1')
                {
                    num_island++;
                    dfs(grid, i,j);
                }
            }
        }
        return num_island;
    }
};