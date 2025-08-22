class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int flag=0,fr=0,lr=0,fc=0,lc=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1&&flag==0)
                {
                    flag=1;
                    fr=i;
                }
                if(grid[i][j]==1)
                lr=i;
            }
        }
        flag=0;
        for(int i=0;i<grid[0].size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                if(grid[j][i]==1&&flag==0)
                {
                    flag=1;
                    fc=i;
                }
                if(grid[j][i]==1)
                lc=i;
            }
        }
        //cout<<fr<<" "<<lr<<" "<<fc<<" "<<lc;
        return (lr-fr+1)*(lc-fc+1);
    }
};