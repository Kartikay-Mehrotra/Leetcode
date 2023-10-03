class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int,int> mp;
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
           ans+= mp[nums[i]-i]++;
        }
        int n=nums.size();
        return (1LL*n*(n-1)/2)-ans;
            
    }
};