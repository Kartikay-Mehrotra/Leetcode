class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int cs=nums[0];
        for(int j=1;j<nums.size();j++)
        {
            int i=nums[j];
            if(cs<0)
                cs=0;
            cs+=i;
            ans=max(ans,cs);
        }
        return ans;
    }
};