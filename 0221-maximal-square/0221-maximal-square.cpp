class Solution {
public:
int solve(vector<vector<char>>& matrix,int i,int j,vector<vector<int>> &dp,int &maxx)
{
    if(i>=matrix.size()||j>=matrix[0].size())
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];

    int right=solve(matrix,i,j+1,dp,maxx);
    int down=solve(matrix,i+1,j,dp,maxx);
    int dia=solve(matrix,i+1,j+1,dp,maxx);

if(matrix[i][j]=='1')
{
    dp[i][j]=1+min({right,down,dia});
    maxx=max(maxx,dp[i][j]);
    return dp[i][j];
}
else
return dp[i][j]=0;
}
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int maxx=0;
        int t=solve(matrix,0,0,dp,maxx);
        return maxx*maxx;
    }
};