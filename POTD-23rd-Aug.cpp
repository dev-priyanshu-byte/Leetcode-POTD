class Solution {
public:
    int calculateArea(int i1,int i2,int j1,int j2,vector<vector<int>>&grid){
        if(i1>i2||j1>j2)
        return 0;
        int minx=31,miny=31,mx=0,my=0;
        for(int i=i1;i<=i2;i++)
            for(int j=j1;j<=j2;j++)
                if(grid[i][j]==1)
                {
                    minx=min(minx,j);
                    mx=max(mx,j);
                    miny=min(miny,i);
                    my=max(my,i);
                }
        return (mx-minx+1)*(my-miny+1);
    }
    int minimumSum(vector<vector<int>>& grid) {
        int a,b,c,ab=INT_MAX,ans=INT_MAX;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<n;i++)
        {
            ab=INT_MAX;
            for(int j=0;j<m;j++)
            {
                a=calculateArea(0,j-1,0,i-1,grid);
                b=calculateArea(j,m-1,0,i-1,grid);
                ab=min(ab,a+b);
            }
            c=calculateArea(0,m-1,i,n-1,grid);
            ans=min(ans,ab+c);
        }
        for(int i=0;i<n;i++)
        {
            ab=INT_MAX;
            for(int j=0;j<m;j++)
            {
                a=calculateArea(0,j-1,i,n-1,grid);
                b=calculateArea(j,m-1,i,n-1,grid);
                ab=min(ab,a+b);
            }
            c=calculateArea(0,m-1,0,i-1,grid);
            //cout<<c<<" "<<ab<<endl;
            ans=min(ans,ab+c);
        }
        for(int i=0;i<m;i++)
        {
            ab=INT_MAX;
            for(int j=0;j<n;j++)
            {
                a=calculateArea(i,m-1,0,j-1,grid);
                b=calculateArea(i,m-1,j,n-1,grid);
                ab=min(ab,a+b);
            }
            c=calculateArea(0,i-1,0,n-1,grid);
            //cout<<c<<" "<<ab<<endl;
            ans=min(ans,ab+c);            
        }
        for(int i=0;i<m;i++)
        {
            ab=INT_MAX;
            for(int j=0;j<n;j++)
            {
                a=calculateArea(0,i-1,0,j-1,grid);
                b=calculateArea(0,i-1,j,n-1,grid);
                ab=min(ab,a+b);
            }
            c=calculateArea(i,m-1,0,n-1,grid);
            //cout<<c<<" "<<ab<<endl;
            ans=min(ans,ab+c);            
        }
        for(int i=0;i<m;i++)
        {
            ab=INT_MAX;
            for(int j=i;j<m;j++)
            {
                a=calculateArea(i,j-1,0,n-1,grid);
                b=calculateArea(j,m-1,0,n-1,grid);
                ab=min(ab,a+b);
            }
            c=calculateArea(0,i-1,0,n-1,grid);
            //cout<<c<<" "<<ab<<endl;
            ans=min(ans,ab+c);            
        }
        for(int i=0;i<n;i++)
        {
            ab=INT_MAX;
            for(int j=i;j<n;j++)
            {
                a=calculateArea(0,m-1,i,j-1,grid);
                b=calculateArea(0,m-1,j,n-1,grid);
                ab=min(ab,a+b);
            }
            c=calculateArea(0,m-1,0,i-1,grid);
            //cout<<c<<" "<<ab<<endl;
            ans=min(ans,ab+c);            
        }
        return ans;
    }
};