class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int i=0,x=0,y=0,count=0;
        while(count!=mat.size()*mat[0].size())
        {
            while(x>=0&&y<mat[0].size())
            {
                ans.push_back(mat[x][y]);
                x--;
                y++;
                count++;
            }
            x++;
            y--;
            if(y!=mat[0].size()-1)
            y++;
            else
            x++;
            while(y>=0&&x<mat.size()){
                ans.push_back(mat[x][y]);
                x++;
                y--;
                count++;
            }
            x--;
            y++;                                              
            if(x!=mat.size()-1)
            x++;
            else
            y++;
        }
        return ans;
    }
};
