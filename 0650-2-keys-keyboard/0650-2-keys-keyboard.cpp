class Solution {
public:
    int solve(int steps,int val,int copy,int n)
    {
        if(steps>n ||val>n)
        return INT_MAX;

        if(val==n)
        return steps;

        return min(solve(steps+2,val*2,val,n),solve(steps+1,val+copy,copy,n));
    }
    int minSteps(int n) {
        if(n==1)
        return 0;

        return solve(1,1,1,n);
    }
};