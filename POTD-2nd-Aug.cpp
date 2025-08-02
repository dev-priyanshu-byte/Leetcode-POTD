class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {

        long long mini=INT_MAX;
        long long cost=0;
        unordered_map<int,int> mp1,mp2;
        vector<int> nb1,nb2;
        if(basket1.size()!=basket2.size())
        return -1;
        for(int i=0;i<basket1.size();i++)
        {
            mp1[basket1[i]]++;
            if(basket1[i]<mini)
            mini=basket1[i];
        }
        for(int i=0;i<basket2.size();i++)
        {
            mp2[basket2[i]]++;
            if(basket2[i]<mini)
            mini=basket2[i];
        }
        for(auto i:mp1)
        {
            int key=i.first,val=i.second;
            if(val>mp2[key])
            {
                mp1[key]-=mp2[key];
                mp2[key]=0;
                val=mp1[key];
                if(val%2==1)
                return -1;
                while(val!=0)
                {
                    nb1.push_back(key);
                    val-=2;
                }
            }
        }
        for(auto i:mp2)
        {
            int key=i.first,val=i.second;
            if(val>mp1[key])
            {
                mp2[key]-=mp1[key];
                mp1[key]=0;
                val=mp2[key];
                if(val%2==1)
                return -1;
                while(val!=0)
                {
                    nb2.push_back(key);
                    val-=2;
                }
            }
        }
        sort(nb1.begin(),nb1.end());
        sort(nb2.begin(),nb2.end());
        int x1=nb1.size()-1,x2=0,y1=nb2.size()-1,y2=0;
        while(x1>=x2&&y1>=y2)
        {
            if(nb1[x1]>nb2[y1])
            {
                int c=min(nb1[x1],nb2[y2]);
                if(c<=2*mini)
                {
                    cost+=c;
                    x1--;
                    y2++;
                }
                else
                {
                    cost+=2*mini;
                    x1--;
                    y1--;
                }
            }
            else
            {
                int c=min(nb2[y1],nb1[x2]);
                if(c<=2*mini)
                {
                    cost+=c;
                    y1--;
                    x2++;
                }
                else
                {
                    cost+=2*mini;
                    y1--;
                    x1--;
                }
            }
        }
        return cost;
    }
};