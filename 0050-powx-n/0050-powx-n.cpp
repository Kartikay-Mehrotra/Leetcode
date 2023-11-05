class Solution {
public:
    double solve(double x,long n)
    {
        if(n<=0)
            return 1;
        if(n&1)
        {
            return x*solve(x,n-1);
        }
        else
            return solve(x*x,n/2);
    }
    double myPow(double x, int n) {
        if(n==1 || x==1)
            return x;
        if(n==0)
            return 1;
        int sign=n<0?-1:1;
        long n1=abs(n);
        double val=solve(x,n1);
        val=sign==-1?1/val:val;
        return val;
    }
};