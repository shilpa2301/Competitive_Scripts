class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int nr=grid.size();
        int nc=grid[0].size();
        int i,j;
        for(j=0; j<nc; j++)
        {
           // cout<<j<<"\n";
            if(grid[0][j]==1)
            {
                for(i=0; i<nr; i++)
                {
                    grid[i][j]=!grid[i][j];
                 //   cout<<grid[i][j]<<", ";
                }
            }
        }
        int sum;
        for(i=0; i<nr; i++)
        {
            sum=0;
            for(j=0; j<nc; j++)
            {
                sum=sum+grid[i][j];
            }
          //  cout<<"i= "<<i<<" sum="<<sum<<endl;
            if(sum !=0 && sum !=nc)
                return false;
        }
        return true;
    }
};