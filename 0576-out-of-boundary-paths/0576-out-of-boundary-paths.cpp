class Solution {
public:
    const int mod=1000000007;
    int solve(int i,int j,int maxMove,int n,int m,vector<vector<vector<int>>>& dp)
    {
        if(i<0 || j<0 || (i==m || j==n))
            return 1;
        if(dp[i][j][maxMove]!=-1)
            return dp[i][j][maxMove];
        if(maxMove==0)
            return 0;
        return dp[i][j][maxMove]=((solve(i-1,j,maxMove-1,n,m,dp)%mod + solve(i,j-1,maxMove-1,n,m,dp)%mod)%mod+(solve(i+1,j,maxMove-1,n,m,dp)%mod + solve(i,j+1,maxMove-1,n,m,dp)%mod)%mod)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return solve(startRow,startColumn,maxMove,n,m,dp);
    }
};