class Solution {
public:
int cou(vector<int>& coins, int amount,int n, vector<vector<int>> &dp)
{
    if(amount==0)
    return 0;

    if(n<0)
    return 1e9;

    if(dp[n][amount]!=-1)
    return dp[n][amount];

    int leave=cou(coins,amount,n-1,dp);
    int r=1e9;
    if(coins[n]<=amount)
    r=1+cou(coins,amount-coins[n],n,dp);

    return dp[n][amount]=min(leave,r);
}
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int count=cou(coins,amount,coins.size()-1,dp);
        if(count==1e9)
        return -1;

        return count;
    }
};