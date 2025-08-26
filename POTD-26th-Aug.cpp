class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double diag=0;
        int area=0,d;
        for(auto i:dimensions){
            d=i[0]*i[0]+i[1]*i[1];
            if(d>diag)
            {
                diag=d;
                area=i[0]*i[1];
            }
            else if(d==diag)
            {
                area=max(area,i[0]*i[1]);
            }
            else
            continue;
        }
        return area;
    }
};