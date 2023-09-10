class Solution {
public:
int solve(int i,int n,string& s,vector<int>& dp)
{
    if(i>=n)
    return 1;
    else if(s[i]=='0')
    return 0;
    else if(i==s.size()-1)
    return 1;
   
    if(dp[i]!=-1)
    return dp[i];
    if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6' && s[i+1]>='0'))
    return dp[i]=solve(i+1,n,s,dp)+solve(i+2,n,s,dp);
    else
    return dp[i]=solve(i+1,n,s,dp);
}
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
      
        return solve(0,s.size(),s,dp);
    }
};