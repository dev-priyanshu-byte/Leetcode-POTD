class Solution {
public:
    void sort1(int i,int j,vector<vector<int>>&grid){
        int x=i,y,mx,my,temp;
        for(int k=j;k<grid.size();k++){
            y=x;
            mx=x;
            my=k;
            for(int l=k;l<grid.size();l++){
                if(grid[y][l]<grid[mx][my])
                {
                    mx=y;
                    my=l;
                }
                y++;
            }
            temp=grid[mx][my];
            grid[mx][my]=grid[x][k];
            grid[x][k]=temp;
            x++;
        }
    }
    void sort2(int i,int j,vector<vector<int>>&grid){
        int x=i,y,mx,my,temp;
        for(int k=j;x<grid.size();k++){
            y=x;
            mx=x;
            my=k;
            for(int l=k;y<grid.size();l++){
                if(grid[y][l]>grid[mx][my])
                {
                    mx=y;
                    my=l;
                }
                y++;
            }
            temp=grid[mx][my];
            grid[mx][my]=grid[x][k];
            grid[x][k]=temp;
            x++;
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        for(int i=1;i<grid.size();i++)
            sort1(0,i,grid);
        for(int i=0;i<grid.size();i++)
            sort2(i,0,grid);
        return grid;
    }
};