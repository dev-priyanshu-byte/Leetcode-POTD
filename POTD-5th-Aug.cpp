class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count=0,flag=0;
        for(int i=0;i<fruits.size();i++)
        {
            flag=0;
            for(int j=0;j<baskets.size();j++)
            {
                if(baskets[j]>=fruits[i])
                {
                    baskets[j]=0;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                count++;
        }
        return count;
    }
};