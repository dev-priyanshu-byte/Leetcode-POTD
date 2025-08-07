class Solution {
public:
    int firstChild(vector<vector<int>>&fruits, int x,int y){
        if(x==fruits.size())  return 0;
        else{
            int temp=fruits[x][y];
            fruits[x][y]=0;
            return temp+firstChild(fruits,x+1,y+1);
        }
    }
    int secondChild(vector<vector<int>>&fruits,vector<vector<int>>& cost,int x,int y){
        if(x==fruits.size()||y==fruits.size()||x<0||y<0||x+y<fruits.size()-1)
        return pow(10,6.5)*-1;

        if(cost[x][y]!=-1)
        return cost[x][y]; 

        if(x==fruits.size()-1&&y==0)
        return cost[x][y]=fruits[x][y];

        return cost[x][y]=fruits[x][y]+ 
        max(max(secondChild(fruits,cost,x-1,y-1),secondChild(fruits,cost,x+1,y-1)),secondChild(fruits,cost,x,y-1));
    }
    int thirdChild(vector<vector<int>>&fruits,vector<vector<int>>&cost,int x,int y){
        if(x<0||y==fruits.size()||x+y<fruits.size()-1)
        return pow(10,6.5)*-1;

        if(cost[x][y]!=-1)
        return cost[x][y];

        if(y==fruits.size()-1&&x==0)
        return cost[x][y]=fruits[x][y]; 

        return cost[x][y]=fruits[x][y]+ 
        max(max(thirdChild(fruits,cost,x-1,y-1),thirdChild(fruits,cost,x-1,y+1)),thirdChild(fruits,cost,x-1,y)); 
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        vector<vector<int>>cost;
        int fc= firstChild(fruits,0,0);
        cost=vector<vector<int>>(fruits.size(),vector<int>(fruits.size(),-1));
        int sc=secondChild(fruits,cost,fruits.size()-1,fruits.size()-1);
        cost=vector<vector<int>>(fruits.size(),vector<int>(fruits.size(),-1));
        int tc=thirdChild(fruits,cost,fruits.size()-1,fruits.size()-1);
    return fc+sc+tc;
    }
};