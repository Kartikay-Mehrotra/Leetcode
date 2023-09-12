class Solution {
public:
    int mini=0;
    int solve(int i,int j,int prev,vector<vector<int>>& mat,vector<vector<int>> & dp)
    {
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || mat[i][j]<=prev)
            return -1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j]=1+max({solve(i-1,j+1,mat[i][j],mat,dp),solve(i,j+1,mat[i][j],mat,dp),solve(i+1,j+1,mat[i][j],mat,dp)});
    }
    int maxMoves(vector<vector<int>>& matrix) {
         int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        for(int i=0;i<m;i++)
        {
            mini=max(mini,solve(i,0,-1,matrix,dp));
        }

        return mini;
    }
};