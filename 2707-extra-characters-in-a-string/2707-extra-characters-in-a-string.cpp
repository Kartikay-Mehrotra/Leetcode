class Solution {
public:
    int solve(int indx,string& s,map<string,int>& mp,vector<int>& dp)
    {
        if(indx==s.size())
            return 0;
        if(dp[indx]!=-1)
            return dp[indx];
        int ans=INT_MAX;
        string temp="";
        for(int i=indx;i<s.size();i++)
        {
            temp+=s[i];
            if(mp.count(temp))
            {
                ans=min(ans,solve(i+1,s,mp,dp));
            }
        }
        ans=min(ans,1+solve(indx+1,s,mp,dp));
        return dp[indx]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        map<string,int> mp;
        for(auto i:dictionary)
            mp[i]++;
        vector<int> dp(s.size(),-1);
        return solve(0,s,mp,dp);
    }
};