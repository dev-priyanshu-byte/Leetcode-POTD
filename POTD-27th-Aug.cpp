class Solution {
public:
inline bool valid(int x) {
    return (x == 0 || x == 2);
}

void makeA(vector<vector<int>>& a, vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    a.assign(m, vector<int>(n, 1));
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (!valid(grid[i][j])) { a[i][j] = 0; continue; }
            if (i + 1 < m && j + 1 < n &&
                valid(grid[i+1][j+1]) &&
                grid[i][j] != grid[i+1][j+1]) {
                a[i][j] = 1 + a[i+1][j+1];
            }
        }
    }
}

void makeB(vector<vector<int>>& b, vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    b.assign(m, vector<int>(n, 1));
    for (int i = 0; i < m; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (!valid(grid[i][j])) { b[i][j] = 0; continue; }
            if (i - 1 >= 0 && j + 1 < n &&
                valid(grid[i-1][j+1]) &&
                grid[i][j] != grid[i-1][j+1]) {
                b[i][j] = 1 + b[i-1][j+1];
            }
        }
    }
}

void makeC(vector<vector<int>>& c, vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    c.assign(m, vector<int>(n, 1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!valid(grid[i][j])) { c[i][j] = 0; continue; }
            if (i - 1 >= 0 && j - 1 >= 0 &&
                valid(grid[i-1][j-1]) &&
                grid[i][j] != grid[i-1][j-1]) {
                c[i][j] = 1 + c[i-1][j-1];
            }
        }
    }
}

void makeD(vector<vector<int>>& d, vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    d.assign(m, vector<int>(n, 1));
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (!valid(grid[i][j])) { d[i][j] = 0; continue; }
            if (i + 1 < m && j - 1 >= 0 &&
                valid(grid[i+1][j-1]) &&
                grid[i][j] != grid[i+1][j-1]) {
                d[i][j] = 1 + d[i+1][j-1];
            }
        }
    }
}
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        vector<vector<int>> a;
        vector<vector<int>> b;
        vector<vector<int>> c;
        vector<vector<int>> d;
        makeA(a,grid);
        makeB(b,grid);
        makeC(c,grid);
        makeD(d,grid);
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                ans=max(ans,1);
                if(grid[i][j]!=0&&grid[i][j]!=2)
                continue;
                
                if(i-c[i][j]>=0&&j-c[i][j]>=0&&grid[i-c[i][j]+1][j-c[i][j]+1]==2&&grid[i-c[i][j]][j-c[i][j]]==1)
                {
                    ans=max(ans,c[i][j]+d[i][j]);
                }
                if(i+a[i][j]<grid.size()&&j+a[i][j]<grid[0].size()&&grid[i+a[i][j]-1][j+a[i][j]-1]==2&&grid[i+a[i][j]][j+a[i][j]]==1)
                {
                    ans=max(ans,a[i][j]+b[i][j]);
                }
                if(i+d[i][j]<grid.size()&&j-d[i][j]>=0&&grid[i+d[i][j]-1][j-d[i][j]+1]==2&&grid[i+d[i][j]][j-d[i][j]]==1)
                {
                    ans=max(ans,d[i][j]+a[i][j]);
                }
                if(i-b[i][j]>=0&&j+b[i][j]<grid[0].size()&&grid[i-b[i][j]+1][j+b[i][j]-1]==2&&grid[i-b[i][j]][j+b[i][j]]==1)
                {
                    ans=max(ans,b[i][j]+c[i][j]);
                }
                else continue;
            }
        }
        return ans;
    }
};