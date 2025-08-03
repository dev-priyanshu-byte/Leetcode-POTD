class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int x=0;
        int best=0,steps=0,count=0;
        for(int i=0;i<fruits.size();i++)
        {
            if(startPos-fruits[i][0]>k)
            {
                x++;
                continue;
            }
            if(fruits[i][0]-startPos>k)
            break;
            if(fruits[i][0]>startPos)
            {
                steps=(startPos-fruits[x][0])*2+fruits[i][0]-startPos;
            }
            else
            {
                steps=-fruits[x][0]+startPos;
            }
            count+=fruits[i][1];

            while(x<=i&&steps>k){
                count-=fruits[x][1];
                x++;
                steps=(startPos-fruits[x][0])*2+fruits[i][0]-startPos;
            }
            best=max(best,count);
        }
        int y=fruits.size()-1;
        count=0;
        for(int i=fruits.size()-1;i>=0;i--){
            if(fruits[i][0]-startPos>k)
            {
                y--;
                continue;
            }
            if(startPos-fruits[i][0]>k)
            break;
            if(fruits[i][0]<startPos)
            {
                steps=2*(fruits[y][0]-startPos)+startPos-fruits[i][0];
            }
            else
            {
                steps=fruits[y][0]-startPos;
            }
            count+=fruits[i][1];

            while(y>=i&&steps>k)
            {
                count-=fruits[y][1];
                y--;
                steps=2*(fruits[y][0]-startPos)+startPos-fruits[i][0];
            }
            best=max(best,count);
        }
        return best;
    }
};