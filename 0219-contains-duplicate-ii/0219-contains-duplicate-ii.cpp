class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }
        for(auto i:mp)
        {
            vector<int> t=i.second;
            for(int j=1;j<t.size();j++)
            {
                if(abs(t[j-1]-t[j])<=k)
                    return true;
            }
        }
        return false;
    }
};