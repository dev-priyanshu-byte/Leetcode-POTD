class Solution {
public:
    int numSubmat(vector<vector<int>>& matrix) {
        int count=0,x,rects;
        for(int i=matrix.size()-2;i>=0;i--){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0)
                continue;
                else
                matrix[i][j]+=matrix[i+1][j];
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                x=j;
                rects=matrix[i][j];
                while(x<matrix[0].size()&&matrix[i][x]!=0){
                    rects=min(rects,matrix[i][x]);
                    count+=rects;
                    x++;
                }
            }
        }
        return count;
    }
};