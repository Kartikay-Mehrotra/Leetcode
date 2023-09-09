class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
           if(nums.size() <= 1)
         return false;

        unordered_map<int,int> mp;
        int s=0;
        mp[0]=0;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            if(mp.count(s%k)==0)
            {
                mp[s%k]=i+1;
            }
            else if((i+1)-mp[s%k] >=2)
            {
                return true;
            }
        }
        return false;
        
    }
};