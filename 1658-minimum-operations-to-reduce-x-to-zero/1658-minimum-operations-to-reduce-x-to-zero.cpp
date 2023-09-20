class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int j=0;
        int sum=0;
        for(auto i:nums)
            sum+=i;
        sum-=x;
        if(sum<0)
            return -1;
        int k=0;
        int ans=-1;
        for(int i=0;i<nums.size();i++)
        {
            k+=nums[i];
            while(k>sum)
            {
                k-=nums[j];
                j++;
            }
            if(k==sum)
            {
                ans=max(ans,i-j+1);
            }
        }
        return ans==-1?-1:nums.size()-ans;
        
        
    }
};