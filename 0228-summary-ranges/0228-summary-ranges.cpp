class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int i=0;
        int j=0;
        for(i=0;i<nums.size();i++)
        {
            j=i;
            while(j+1<nums.size() && nums[j+1]==nums[j]+1)
                j++;
            string temp="";
            
            if(j>i)
                temp=to_string(nums[i])+"->"+to_string(nums[j]);
            else
                temp=to_string(nums[i]);
            ans.push_back(temp);
            i=j;      
        }
        return ans;
        
    }
};