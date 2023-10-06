class Solution {
public:
    int solve(int n,int target,int limit,vector<vector<int>>& dp)
    {
        if(target==0)
            return 1;
        if(n>=limit)
            return 0;
        if(dp[n][target]!=-1)
            return dp[n][target];
        
        if(n<=target)
        {
            dp[n][target]=n*solve(n,target-n,limit,dp);
        }
        dp[n][target]=max(dp[n][target],solve(n+1,target,limit,dp));
        
        return dp[n][target];
    }
    int integerBreak(int n) {
     vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(1,n,n,dp);
    }
};