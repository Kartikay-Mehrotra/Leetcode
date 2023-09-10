class Solution {
public:
int solve(vector<string>& strs,int m,int n,int idx,vector<vector<vector<int>>> &dp)
{
    if(m==0 && n==0)
    return 0;
    if(idx==strs.size())
    return 0;
    if(dp[idx][m][n]!=-1)
    return dp[idx][m][n];

    int one=count(strs[idx].begin(),strs[idx].end(),'1');
    int zero=strs[idx].size()-one;
    int ans=INT_MIN;
    if(m>=zero && n>=one)
    {
        ans=max(ans,1+solve(strs,m-zero,n-one,idx+1,dp));
    }
    ans=max(ans,solve(strs,m,n,idx+1,dp));

    return dp[idx][m][n]=ans;
 
}
    int findMaxForm(vector<string>& strs, int m, int n) {
 vector<vector<vector<int>>> dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(strs, m, n, 0, dp);
         }
};