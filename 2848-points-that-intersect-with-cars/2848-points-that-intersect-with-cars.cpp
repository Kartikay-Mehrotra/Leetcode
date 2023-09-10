class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> output;
        
        for(auto i:nums)
        {
            if(output.size()==0 || output.back()[1]<i[0])
                output.push_back(i);
            else
            {
                output.back()[1]=max(output.back()[1],i[1]);
            }
        }
        int ans=0;
        for(auto i:output)
        {
            ans+=(i[1]-i[0]+1);
        }
        return ans;
    }
};