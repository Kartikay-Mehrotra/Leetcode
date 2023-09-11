class Solution {
public:
   bool solve(int i,int j,vector<int> &nums,vector<vector<int>> &dp,int &m){
       if(i==j) return true;
       int sum=0;
       for(int k=i; k<=j; k++){
           sum+=nums[k];
       }
       if(sum<m){return false;}
       if(dp[i][j]!=-1){
           return dp[i][j];
       }
       int ans=0;
       for(int k=i; k<j; k++){
           int left=solve(i,k,nums,dp,m);
           int right=solve(k+1,j,nums,dp,m);
            ans=(ans || (left && right));
       }
       return dp[i][j]=ans;
   }

    bool canSplitArray(vector<int>& nums, int m) {
      int n=nums.size();
      if(n<=2){ return true;}
      vector<vector<int>> dp(n,vector<int> (n,-1));
      return solve(0,n-1,nums,dp,m);  
       }
};