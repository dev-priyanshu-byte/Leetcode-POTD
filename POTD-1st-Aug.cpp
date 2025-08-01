class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        vector<int> temp;
        temp={1};
        pascal.push_back(temp);
        temp.clear();
        for(int i=2;i<=numRows;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(j==0||j==i-1)
                temp.push_back(1);
                else
                temp.push_back(pascal[i-2][j]+pascal[i-2][j-1]);
            }
            pascal.push_back(temp);
            temp.clear();
        }
        return pascal;
    }
};