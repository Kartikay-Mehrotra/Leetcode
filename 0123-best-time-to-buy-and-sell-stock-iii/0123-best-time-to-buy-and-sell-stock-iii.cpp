class Solution {
public:
    int solve(vector<int>& prices,int i,int buy,int cap, vector<vector<vector<int>>> &dp)
    {
        if(i==prices.size())
        return 0;
        if(cap==0)
        return 0;

        if(dp[i][buy][cap]!=-1)
        return dp[i][buy][cap];

        int profit=0;
        if(buy)
        {
            profit=max(-prices[i]+solve(prices,i+1,0,cap,dp),solve(prices,i+1,1,cap,dp));
        }
        else
        profit=max(prices[i]+solve(prices,i+1,1,cap-1,dp),solve(prices,i+1,0,cap,dp));

        return dp[i][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int i=0;
        int buy=1;
        int cap=2;
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,i,buy,cap,dp);
    }
};