class Solution {
public:
long g=1;
    bool isPowerOfTwo(int n) {
        if(g>n)
        return false;
        else if(g==n)
        return true;
        else
        {
            g*=2;
            return isPowerOfTwo(n);
        }
    }
};