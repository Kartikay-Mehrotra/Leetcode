class Solution {
public:
static bool comp(string& a,string& b)
{
    return a.size()<b.size();
}
bool isv(string &s1,string &s2)
    {
        if(s1.size()==s2.size())  return false;
        if(s1.size()>s2.size()+1) return false;
         int i=0;
         int j=0;
        while(i<s1.size())
            if(j<s2.size() && s1[i]==s2[j])
                i++,j++;
            else
                i++;
        if(i==s1.size() && j==s2.size())
            return true;
        else
            return false;
    }
int solve(int indx,int prev,vector<string>& words,vector<vector<int>>& dp)
{
    if(indx>words.size())
    return 0;
    if(dp[indx][prev]!=-1)
    return dp[indx][prev];

    int maxl=0;
    if(prev==0 || isv(words[indx-1],words[prev-1]))
    {
        maxl=1+solve(indx+1,indx,words,dp);
    }
    return dp[indx][prev]=max(maxl,solve(indx+1,prev,words,dp));
}
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),comp);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1,0,words,dp);
    }
};