class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k==0)
        return 1;
        int ind=k+maxPts-1;
        double ans=0,x=0;
        vector<double> prob(ind+1,0);
        while(ind!=0){
            if(ind>=k)
            {
                if(ind<=n)
                x=1;
                else
                x=0;
            }
            else
            {
                if(ind+maxPts+1>=prob.size())
                x=prob[ind+1]/maxPts;
                else
                x=(prob[ind+1]-prob[ind+maxPts+1])/maxPts;
            }

            if(ind<=maxPts)
            ans+=x;

            if(ind+1<prob.size())
            prob[ind]=prob[ind+1]+x;
            else
            prob[ind]=x;

            ind--;
        }
        return ans/maxPts;
    }
};