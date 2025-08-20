class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int squares=0;
        vector<vector<int>> square;
        square=matrix;
        for(int size=0;size<matrix.size();size++){
            for(int i=0;i<matrix.size();i++){
                for(int j=0;j<matrix[0].size();j++){
                    if(i+size>=matrix.size()||j+size>=matrix[0].size()||square[i][j]==0||(size>0&&square[i+1][j+1]==0)||matrix[i+size][j]==0||matrix[i][j+size]==0) square[i][j]=0;
                    else squares++;
                }
            }
        }
        return squares;
    }
};