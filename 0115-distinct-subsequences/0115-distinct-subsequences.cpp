class Solution {
public:
int solve(int i,int j,string& s,string &t,vector<vector<int>>& dp)
{
    if(j<0)
    return 1;
    if(i<0)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];

    if(s[i]==t[j])
    {
        int bth=solve(i-1,j-1,s,t,dp);
        int o=solve(i-1,j,s,t,dp);
        dp[i][j]=(bth+o);
    }
    else
    dp[i][j]=solve(i-1,j,s,t,dp);

    return dp[i][j];
}
    int numDistinct(string s, string t) {
        
        int n1=s.size();
        int n2=t.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return solve(n1-1,n2-1,s,t,dp);
    }
};