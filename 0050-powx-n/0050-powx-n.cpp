class Solution {
public:
    double solve(double x,long n)
    {
        if(n==0)
            return 1;
        if(n%2==0)
        {
            return solve(x*x,n/2);
        }
        
        return x*solve(x,n-1);
    }
    double myPow(double x, int n) {
        if(n==0)
            return 1;
      long l=abs(n);
        double val=solve(x,l);
        return n>0?val:1/val;
    }
};