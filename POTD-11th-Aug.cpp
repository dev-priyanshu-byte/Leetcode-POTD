class Solution {
public:
    void reverse(vector<int>&vec){
        int n=vec.size(),temp;
        for(int i=0;i<n/2;i++)
        {
            temp=vec[i];
            vec[i]=vec[n-i-1];
            vec[n-i-1]=temp;
        }
    }
    vector<int> binary(int n){
        int power=pow(2,30);
        vector<int> ans;
        while(n!=0)
        {
            if(power<=n)
            {
                ans.push_back(power);
                n=n-power;
            }
            power=power/2;
        }
        return ans;
    }
    vector<vector<int>> multiply(vector<int>& powers){
        vector<vector<int>> products(powers.size(),vector<int>(powers.size(),1));
        long l=1;
        int mod=pow(10,9)+7;
        for(int i=0;i<powers.size();i++)
        {
            products[i][i]=powers[i];
            for(int j=i+1;j<powers.size();j++)
            {
                products[i][j]=l*products[i][j-1]*powers[j]%mod;
            }
        }
        return products;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers=binary(n);
        reverse(powers);
        vector<vector<int>> products=multiply(powers);
        vector<int> res;
        for(int i=0;i<queries.size();i++)
        {
            res.push_back(products[queries[i][0]][queries[i][1]]);
        }
        return res;
    }
};