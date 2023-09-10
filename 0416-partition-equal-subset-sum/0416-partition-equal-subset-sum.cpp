class Solution {
public:
    bool f(int i, int sum, vector<int>& nums, vector<vector<int>>& dp){
        if(sum==0){return true;}
        if(i==0){return nums[i]==sum;}
        if(dp[i][sum]!=-1){return dp[i][sum];}
        bool nt=f(i-1, sum, nums, dp);
        bool t=false;
        if(nums[i]<=sum){
            t=f(i-1, sum-nums[i], nums, dp);
        }
        return dp[i][sum]=(t|nt);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }
        if(sum%2){return false;}
        sum/=2;
        vector<vector<int>>dp(nums.size(), vector<int>(sum+1, -1));
        return f(nums.size()-1, sum, nums, dp);
    }
};
// class Solution {
// public:
//     bool bottomUp(int target,vector<int>& nums){
//             vector<vector<int>> dp(nums.size()+1,vector<int>( target+1,0));
//             for(int i=0;i<nums.size();i++)
//                 dp[i][0]=1;
            
//             for(int index=nums.size()-1;index>=0;index--){
//                 for(int t=1;t<=target;t++){
//                     bool include=0;
//                 if(t-nums[index]>=0)
//                     include=dp[index+1][t-nums[index]];
//                     bool exclude=dp[index+1][t];
//                     dp[index][t]=(include|| exclude);
//                 }
//             }
//             return dp[0][target];
//     }
//     bool canPartition(vector<int>& nums) {
//         int sum=0;
//         for(int i=0;i<nums.size();i++){
//             sum+=nums[i];
//         }
//         if(sum& 1)
//             return false;
//         int target=sum/2;
//         int index=0;
//         return bottomUp(target,nums);
//     }
// };