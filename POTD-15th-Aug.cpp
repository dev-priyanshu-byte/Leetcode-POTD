class Solution {
public:
long g=1; 
    bool isPowerOfFour(int n) {
        if(g>n)
        return false;
        else if(g==n)
        return true;
        else
        {
            g*=4;
            return isPowerOfFour(n);
        }
        
    }
};