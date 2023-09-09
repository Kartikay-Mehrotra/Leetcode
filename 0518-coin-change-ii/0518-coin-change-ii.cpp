class Solution{
    
public:
      int solve(vector<int>& coins, int sum,int n,vector<vector<int>> &dp)
    {
        if(sum==0)
        return 1;
       if(n<0 || sum<0)
       return 0;
        if(dp[n][sum]!=-1)
        return dp[n][sum];
        int r=0;
        int l=solve(coins,sum,n-1,dp);
        if(coins[n]<=sum)
        r=solve(coins,sum-coins[n],n,dp);
        return dp[n][sum]=(l+r);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));        
        return solve(coins,amount,coins.size()-1,dp);

    }
};

