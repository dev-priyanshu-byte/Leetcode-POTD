class Solution {
public:
    double soupProb(int i,int j, vector<vector<double>>&cost){
        if(i<=0&&j<=0)
        return 0.5;
        else if(i<=0)
        return 1;
        else if(j<=0)
        return 0;
        else if(cost[i][j]!=-1)
        return cost[i][j];
        else
        return cost[i][j]=0.25*(soupProb(i-100,j,cost)+soupProb(i-75,j-25,cost)+soupProb(i-50,j-50,cost)+soupProb(i-25,j-75,cost));
    }
    double soupServings(int n) {
        if(n>4300)
        return 1;
        vector<vector<double>> cost(n+1,vector<double>(n+1,-1));
        return soupProb(n,n,cost);
    }
};