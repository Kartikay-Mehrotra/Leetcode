class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans=0;
        map<int,int> mp;
        int j=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            auto front=mp.begin();
            auto end=mp.end();
            end--;
            while((end->first)-(front->first)>limit)
            {
                mp[nums[j]]--;
                if(mp[nums[j]]==0)mp.erase(nums[j]);
                front=mp.begin();
                end=mp.end();
                end--;
                j++;
            }
            if((end->first)-(front->first)<=limit)
                ans=max(ans,i-j+1);
        
        }
        return ans;
    }
};