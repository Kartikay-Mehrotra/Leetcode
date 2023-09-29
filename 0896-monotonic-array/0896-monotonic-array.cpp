class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size()==1)
        return true;
        bool asc=true;
        int t=0;
        while(t+1<nums.size())
        {
            if(nums[t]>nums[t+1]){
            asc=false;
            break;
        }
        t++;
        }

        for(int i=1;i<nums.size();i++)
        {
            if(asc && nums[i-1]<=nums[i])
            {
                continue;
            }
            else if(!asc && nums[i-1]>=nums[i])
            {
                continue;
            }
            else
            return false;
        }        
        return true;
    }
};