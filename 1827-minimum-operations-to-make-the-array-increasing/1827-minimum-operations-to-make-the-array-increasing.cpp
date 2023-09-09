class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        int m=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>m)
            {
                m=nums[i];
            }
            else
            {
                ans+=(m-nums[i]+1);
                m+=1;
            }
        }
        return ans;
    }
};