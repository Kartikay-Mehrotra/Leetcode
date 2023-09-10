class Solution {
public:
    int helper(int i,int j,string &s,string &p,vector<vector<int>>& dp){
     
     if(i==0 && j==0 )    return true;
     
     if(i==0 || j==0 )    {
        
        if(i==0 && p[j-1]=='*') return helper(i,j-1,s,p,dp);  
        else                    return false;
         
     }
    
    if(dp[i][j]!=-1) return dp[i][j];

    if(p[j-1]=='*' || p[j-1]=='?' ){
        
     if(p[j-1]=='?') return dp[i][j]=helper(i-1,j-1,s,p,dp);
     else            return dp[i][j]=(helper(i-1,j,s,p,dp) || helper(i-1,j-1,s,p,dp) || helper(i,j-1,s,p,dp));
        
    }
    else {
        if(s[i-1]==p[j-1]) return dp[i][j]=helper(i-1,j-1,s,p,dp);
        else               return false;    
    }
}

bool isMatch(string s, string p) {

    int n1=s.size();
    int n2=p.size();
    
    vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
    return helper(s.size(),p.size(),s,p,dp);
}
};