class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int oneCount=0,zeroCount=0;
       int ans=0,x=0;
       for(int i=0;i<nums.size();i++){
        if(nums[i]==0)
        zeroCount++;
        else
        oneCount++;
        while(x<i&&zeroCount>1)
        {
            if(nums[x]==0)
            zeroCount--;
            else
            oneCount--;
            x++;
        }
        ans=max(ans,oneCount);
       }
       if(ans==nums.size())
       ans--;
       return ans;
    }
};