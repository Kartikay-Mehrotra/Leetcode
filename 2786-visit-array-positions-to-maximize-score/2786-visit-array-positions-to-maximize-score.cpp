class Solution {
public:
    long long helper(int index,int p, vector<int>&nums,int x,vector<vector<long long>>&dp){
        int n= nums.size();
        if(index>=n) return 0;
        if(dp[index][p]!=-1) return dp[index][p];
        long long take=0;
        long long nottake=0;
        nottake= helper(index+1,p,nums,x,dp);
        if(nums[index]%2==p){
            take= nums[index]+helper(index+1,p,nums,x,dp);
        }
        else{
            take= nums[index]-x + helper(index+1,!p,nums,x,dp);
        }
        return dp[index][p]= max(take,nottake);
    }
    long long maxScore(vector<int>& nums, int x) {
        int n= nums.size();
        int p= nums[0]%2;
        vector<vector<long long>>dp(n+1,vector<long long>(2,-1));
        return nums[0]+ helper(1,p,nums,x,dp);
        
    }
};