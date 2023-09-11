class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        long long ans = 1;
        int j = -1;
        int mod = 1e9+7;
        for(int i=0;i<nums.size();i++){
           if(nums[i]==1){
               if(j==-1)j=i;
               else ans = (ans%mod *(i-j)%mod)%mod;
               j = i;
               ans %= mod;
           }
        }
        return j==-1 ? 0 : ans%mod;
    } 
};