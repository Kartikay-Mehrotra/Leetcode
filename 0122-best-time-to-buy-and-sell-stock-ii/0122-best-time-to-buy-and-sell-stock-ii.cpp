class Solution {
public:
    int solve(int indx,int buy,vector<int>& prices,vector<vector<int>> &dp)
    {
        if(indx==prices.size())
            return 0;
        if(dp[indx][buy]!=-1)
            return dp[indx][buy];
        int profit=0;
        if(buy)
        {
            profit=max(-prices[indx]+solve(indx+1,0,prices,dp),solve(indx+1,1,prices,dp));
        }
        else
            profit=max(prices[indx]+solve(indx+1,1,prices,dp),solve(indx+1,0,prices,dp));
        
        return dp[indx][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(0,1,prices,dp);
        
    }
};