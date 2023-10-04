class Solution {
public:
    int solve(int i,int open,string& s,vector<vector<int>> &dp)
    {
        if(i==s.length())
        return open==0;
        if(dp[i][open]!=-1)
        return dp[i][open];
        bool ans=false;
        if(s[i]=='(')
        {
            ans=solve(i+1,open+1,s,dp);
        }
        else if(s[i]==')')
     {   if(open)
        ans=solve(i+1,open-1,s,dp);
    }
    else
    {
        ans|=solve(i+1,open,s,dp);
        if(open)
        ans|=solve(i+1,open-1,s,dp);
        ans|=solve(i+1,open+1,s,dp);
    }

    return dp[i][open]=ans;
    }
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),-1));
        return solve(0,0,s,dp);
    }
};