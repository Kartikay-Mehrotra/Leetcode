class Solution {
public:

    int solve(int i, int n, vector<int>arr, int t, vector<vector<int>>&dp){
        if(i>=n ) return 0;
        if(t==0) return 1;
        if(dp[i][t]!=-1) return dp[i][t];
        int take=0;
        if(arr[i]<=t)take=solve(0, n, arr, t-arr[i], dp);
        int ntake=solve(i+1, n, arr, t, dp);
        return dp[i][t]=take+ntake;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        return solve(0, n, nums, target, dp);
    }
};