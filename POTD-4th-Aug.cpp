class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int best=0,x=0,count=0;
        map<int,int> mp;
        for(int i=0;i<fruits.size();i++)
        {
            mp[fruits[i]]++;
            count++;
            while(mp.size()>2){
                mp[fruits[x]]--;
                if(mp[fruits[x]]==0)
                mp.erase(fruits[x]);
                count--;
                x++;
            }
            best=max(best,count);
        }
        return best;
    }
};