class Solution {
public:
int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp,int prev)
{
    if(i<0 || j<0 || i>=matrix.size()|| j>=matrix[0].size() || matrix[i][j]<=prev)
    return 0;

    if(dp[i][j]!=0)
    return dp[i][j];

    int ans=1;
    ans=max(ans,1+solve(i+1,j,matrix,dp,matrix[i][j]));
    ans=max(ans,1+solve(i-1,j,matrix,dp,matrix[i][j]));
    ans=max(ans,1+solve(i,j+1,matrix,dp,matrix[i][j]));
    ans=max(ans,1+solve(i,j-1,matrix,dp,matrix[i][j]));
    dp[i][j]=ans;
    return dp[i][j];
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<int>> dp(r,vector<int>(c,0));
        int ans=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                ans=max(ans,solve(i,j,matrix,dp,-1));
            }
        }
        return ans;
    }
};