class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs=nums[0];
        int maxi=nums[0];
        int l=0;
        for(int i=1;i<nums.size();i++)
        {
           
            
            if(cs<0)
            {
                cs=0;
            }
            cs+=nums[i];
             maxi=max(maxi,cs);
            
        }
        return maxi;
    }
};